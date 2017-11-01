#include "digitmananger.h"

DigitMananger::DigitMananger()
{
    initAll();
}
//初始化，主要功能是
//1.从所有文件中读出的digit赋值给mould
//2.清空所有矩阵
void DigitMananger::initAll()
{
    ifstream fs;
    stringstream ss;
    string filename;
    allArea=0;
    //初始化所有参数
    this->mould.clear();
    this->colorList.clear();
    this->digitList.clear();
    this->ratio.clear();
    this->areas.clear();
    memset(check,-1,sizeof(check));
    //将五个文件中的矩阵读出来，赋值给mould
    for(int i=1;i<=5;i++){
        ss<<i;
        ss>>filename;
        ss.clear();
        filename="./mat/"+filename+".txt";
        fs.open(filename.c_str(),ios::in);
        cout << filename << endl;
        int l,w;
        fs>>l>>w;
        int num=0,num2=0;
        bool mat[10][10],mat2[10][10];
        memset(mat,0,sizeof(mat));
        for(int i=0;i<l;i++){
            for(int j=0;j<w;j++){
                fs>>mat[i][j];
                if(mat[i][j])num++;
                mat2[j][i]=mat[i][j];
                if(mat2[i][j])num2++;
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        filename="";
        fs.close();
        Digit d(l,w,mat,num);
        this->mould.push_back(d);
        Digit d2(w,l,mat2,num2);
        this->mould.push_back(d2);
    }
}


//从矩形区域的右上角开始，生成随机小斑块，调整其坐标，并将其与check矩阵建立索引，直到小版块基本铺满全屏为止
void DigitMananger::addDigitToRect(int xs, int ys, int xe, int ye)
{
    srand(time(NULL));
    int l=ye-ys+1,w=xe-xs+1;
    allArea+=l*w;
    cout<<xs<<" "<<ys<<" "<<xe<<" "<<ye<<endl;
    //局部初始化check矩阵
    for(int i=getMatY(ys);i<=getMatY(ye);i++){
        for(int j=getMatX(xs);j<=getMatX(xe);j++){
            check[i][j]=-1;
        }
    }
    //从左上角开始生成随机小斑块
    int tx=0,ty=0;
    for(int y=ys;y<=ye;y+=ty){
        ty=0;
        for(int x=xs;x<=xe;x+=tx){
            //生成并设置坐标
            Digit d=getRandomDigit();
            d.setLocation(x,y);
            //处理新生成的小斑块与其他小斑块的重合部分
            adjustDigit(d,xs,ys,xe,ye);
            //将新生成的小斑块加入整个小斑块链表
            digitList.push_back(d);
            //这里x每次增量除二是为了增加重合部分，降低最终生成的图案底色占有率过大
            tx=d.getWidth()/2;
            if(ty<d.getLength())ty=d.getLength();
        }
        //除二的原因同x
        ty/=2;
    }
}
//重新生成check
void DigitMananger::rebulidCheck()
{
    for(int k=0;k<digitList.size();k++){
        Digit* d= &digitList[k];
        for(int i=0;i<d->getLength();i++){
            for(int j=0;j<d->getWidth();j++){
                if(d->mat[i][j]){
                    check[getMatY(i+d->getLocationY())][getMatX(j+d->getLocationX())]=k;
                }
            }
        }
    }
}
//根据比例对小斑块进行涂色
void DigitMananger::drawAllDigltColor()
{
    //将digitList打乱顺序
    randomSort();
    //初始化当前各颜色面积
    //将除底色外所有颜色的面积初始化为0
    for(int i=0;i<colorList.size()-1;i++){
        areas.push_back(0);
    }
    //底色面积初始化为全图面积
    areas.push_back(allArea);
    for(int i=0;i<digitList.size();i++){
        drawOneDigltColor(i);
    }
}
//设置要图的颜色列表
void DigitMananger::setColorList(vector<QColor> cL)
{
    this->colorList=cL;

}
//设置要图的颜色比例列表
void DigitMananger::setColorRatio(vector<int> r)
{
    this->ratio=r;
}



void DigitMananger::printCheck(int xs, int ys, int xe, int ye)
{
    for(int i=getMatY(ys);i<=getMatY(ye);i++){
        for(int j=getMatX(xs);j<=getMatX(xe);j++){
            cout<<setw(4)<<check[i][j];
        }
        cout<<endl;
    }
}

//获取一个随机的小斑块
Digit DigitMananger::getRandomDigit()
{
    int c=(int)(rand()%mould.size());
    Digit d=mould[c];
    return d;
}

//重排函数，对digitList进行重新排序，使digitList不在连续，从而增加涂色的随机性
void DigitMananger::randomSort()
{
    for(int i=0;i<digitList.size();i++){
        int c=(int)(rand()%digitList.size());
        swap(digitList[i],digitList[c]);
    }
    rebulidCheck();
}


void DigitMananger::adjustDigit(Digit &d,int xs,int ys,int xe,int ye)
{
    int f=(int)(rand()%2);
    for(int i=0;i<d.getLength();i++){
        for(int j=0;j<d.getWidth();j++){
            if(d.mat[i][j]){
                if(i+d.getLocationY()<ys||i+d.getLocationY()>ye||j+d.getLocationX()>xe||j+d.getLocationX()<xs){
                    d.mat[i][j]=0;
                    d.num--;
                }
                else if(check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())]==-1){
                    check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())]=digitList.size();
                }else{
                    if(f){
                        d.num--;
                        d.mat[i][j]=0;
                    }else{
                        int n=check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())];
                        int ii=i+d.getLocationY()-digitList[n].getLocationY();
                        int jj=j+d.getLocationX()-digitList[n].getLocationX();
                        digitList[n].mat[ii][jj]=0;
                        digitList[n].num--;
                        check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())]=digitList.size();
                    }
                }
            }
        }
    }
}

void DigitMananger::swapDigit(int i1, int i2)
{
    Digit d1=digitList[i1];

    for(int i=0;i<d1.getLength();i++){
        for(int j=0;j<d1.getWidth();j++){
            if(d1.mat[i][j]){
                check[getMatY(i+d1.getLocationY())][getMatX(j+d1.getLocationX())]=i2;
            }
        }
    }
    Digit d2=digitList[i2];
    for(int i=0;i<d2.getLength();i++){
        for(int j=0;j<d2.getWidth();j++){
            if(d2.mat[i][j]){
                check[getMatY(i+d2.getLocationY())][getMatX(j+d2.getLocationX())]=i1;
            }
        }
    }
    swap(digitList[i1],digitList[i2]);
}

//重新绘制x位置的d斑块，并调整check矩阵
void DigitMananger::rebuildDigit(Digit d, int x)
{
    for(int i=0;i<d.getLength();i++){
        for(int j=0;j<d.getWidth();j++){
            if(d.mat[i][j]){
                if(check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())]==-1){
                    check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())]=x;
                }else{
                    int n=check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())];
                    int ii=i+d.getLocationY()-digitList[n].getLocationY();
                    int jj=j+d.getLocationX()-digitList[n].getLocationX();
                    digitList[n].mat[ii][jj]=0;
                    digitList[n].num--;
                    check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())]=x;

                }
            }
        }
    }
    digitList[x]=d;
}
//根据颜色比，获取当前最缺少的颜色
int DigitMananger::getNeedColor()
{
    int x=-1;
    int y=-1;
    for(int i=0;i<ratio.size();i++){
        int t=areas[i]/ratio[i];
        if(y==-1){
            y = t;x=i;
        }else if(y>t){
            y=t;x=i;
        }
    }
    return x;
}

//根据面积比，对一个小斑块进行着色，并在着色后重新调整面积比
void DigitMananger::drawOneDigltColor(int i)
{
    int t=getNeedColor();
    if(t!=-1){
        digitList[i].setColor(colorList[t]);
        areas[t]+=digitList[i].num;
        areas[colorList.size()-1]-=digitList[i].num;
    }
}
//获取坐标再check矩阵中的位置
int DigitMananger::getMatX(int x)
{
    return x+300;
}

int DigitMananger::getMatY(int y)
{
    return y+300;
}
//由小斑点的x,y坐标获得小斑点位于那个小斑块上
int DigitMananger::getDigitLocal(int x, int y)
{
    if(getMatX(x)<0||getMatX(x)>601||getMatY(y)<0||getMatY(y)>601)return -1;
    return check[getMatY(y)][getMatX(x)];
}
//获取小斑块列表
vector<Digit> DigitMananger::getDigitList()
{
    return digitList;
}
