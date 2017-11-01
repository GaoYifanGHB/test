#include"colorhandle.h"


//设置色彩距离阈值，阈值必须是正的，否则设为0
void ColorHandle::setColorDistanceThreshold(int distance)
{
    if (distance < 0)
        distance = 0;
    minDist = distance;
}
void ColorHandle::setColor(cv::Vec3b& tc,int r, int g, int b)
{
    tc[2] = r;
    tc[1] = g;
    tc[0] = b;
}

int ColorHandle::getDistance(Vec3b color1, Vec3b color2)
{
    return abs(color1[0] - color2[0])*abs(color1[0] - color2[0])
            + abs(color1[1] - color2[1])*abs(color1[1] - color2[1])
            + abs(color1[2] - color2[2])*abs(color1[2] - color2[2]);

}

void ColorHandle::readVolorLib()
{
    ifstream fin;
    fin.open("colorLib.data",ios::in);
    for(int i=0;i<20;i++){
        cv::Vec3b tc;
        int r,g,b;
        fin>>r>>g>>b;
        setColor(tc, r, g, b);
        clcm.push_back(tc);
        areas.push_back(0);
    }
}

vector<QColor> ColorHandle::getCls()
{
    return this->qcls;
}

vector<int> ColorHandle::getRls()
{
    return this->rls;
}
//获取色彩距离阈值
int ColorHandle::getColorDistanceThreshold() const
{
    return minDist;
}

//设置需检测的颜色
void ColorHandle::setTargetColor(unsigned char red, unsigned char green, unsigned char blue)
{
    //BGR顺序
    setColor(target,red,green,blue);
}


//设置需检测的颜色
void ColorHandle::setTargetColor(cv::Vec3b color)
{
    target = color;
}
//获取需检测的颜色
cv::Vec3b ColorHandle::getTargetColor() const
{
    return target;
}

void ColorHandle::calculate(const Mat &image)
{
    result.create(image.rows, image.cols, CV_8U);
    //得到迭代器
    cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
    for (; it != itend; ++it)//处理每个像素
    {
        for(int i=0;i<clcm.size();i++){
            if(getDistance(clcm[i],*it)<minDist){
                areas[i]++;
            }
        }
    }
    map<long long,int>hash;
    priority_queue<long long>pri_queue;
    for(int i=0;i<areas.size();i++){
        hash[areas[i]]=i;
        pri_queue.push(areas[i]);
    }
    long long s=pri_queue.top();
    for(int i=0;i<4;i++){
        long long x= pri_queue.top()*10/s;
        if(x==0)x=1;
        rls.push_back(x);
        cls.push_back(clcm[hash[pri_queue.top()]]);
        pri_queue.pop();
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i=0;i<4;i++){
        qcls.push_back(QColor(cls[i][2],cls[i][1],cls[i][0]));
    }

}

cv::Mat ColorHandle::process(const cv::Mat &image)//核心的处理方法
{
    //按需重新分配二值图像
    //与输入图像的尺寸相同，但是只有一个通道
    result.create(image.rows, image.cols, CV_8U);
    //得到迭代器
    cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator itout = result.begin<uchar>();
    for (; it != itend; ++it, ++itout)//处理每个像素
    {
        //计算离目标颜色的距离
        if (getDistance(*it) < minDist)
        {
            *itout = 255;
        }
        else
        {
            *itout = 0;
        }
    }
    return result;
}
