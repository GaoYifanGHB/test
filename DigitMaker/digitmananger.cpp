#include "digitmananger.h"

DigitMananger::DigitMananger()
{
    initAll();
}
//��ʼ������Ҫ������
//1.�������ļ��ж�����digit��ֵ��mould
//2.������о���
void DigitMananger::initAll()
{
    ifstream fs;
    stringstream ss;
    string filename;
    allArea=0;
    //��ʼ�����в���
    this->mould.clear();
    this->colorList.clear();
    this->digitList.clear();
    this->ratio.clear();
    this->areas.clear();
    memset(check,-1,sizeof(check));
    //������ļ��еľ������������ֵ��mould
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


//�Ӿ�����������Ͻǿ�ʼ���������С�߿飬���������꣬��������check������������ֱ��С����������ȫ��Ϊֹ
void DigitMananger::addDigitToRect(int xs, int ys, int xe, int ye)
{
    srand(time(NULL));
    int l=ye-ys+1,w=xe-xs+1;
    allArea+=l*w;
    cout<<xs<<" "<<ys<<" "<<xe<<" "<<ye<<endl;
    //�ֲ���ʼ��check����
    for(int i=getMatY(ys);i<=getMatY(ye);i++){
        for(int j=getMatX(xs);j<=getMatX(xe);j++){
            check[i][j]=-1;
        }
    }
    //�����Ͻǿ�ʼ�������С�߿�
    int tx=0,ty=0;
    for(int y=ys;y<=ye;y+=ty){
        ty=0;
        for(int x=xs;x<=xe;x+=tx){
            //���ɲ���������
            Digit d=getRandomDigit();
            d.setLocation(x,y);
            //���������ɵ�С�߿�������С�߿���غϲ���
            adjustDigit(d,xs,ys,xe,ye);
            //�������ɵ�С�߿��������С�߿�����
            digitList.push_back(d);
            //����xÿ������������Ϊ�������غϲ��֣������������ɵ�ͼ����ɫռ���ʹ���
            tx=d.getWidth()/2;
            if(ty<d.getLength())ty=d.getLength();
        }
        //������ԭ��ͬx
        ty/=2;
    }
}
//��������check
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
//���ݱ�����С�߿����Ϳɫ
void DigitMananger::drawAllDigltColor()
{
    //��digitList����˳��
    randomSort();
    //��ʼ����ǰ����ɫ���
    //������ɫ��������ɫ�������ʼ��Ϊ0
    for(int i=0;i<colorList.size()-1;i++){
        areas.push_back(0);
    }
    //��ɫ�����ʼ��Ϊȫͼ���
    areas.push_back(allArea);
    for(int i=0;i<digitList.size();i++){
        drawOneDigltColor(i);
    }
}
//����Ҫͼ����ɫ�б�
void DigitMananger::setColorList(vector<QColor> cL)
{
    this->colorList=cL;

}
//����Ҫͼ����ɫ�����б�
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

//��ȡһ�������С�߿�
Digit DigitMananger::getRandomDigit()
{
    int c=(int)(rand()%mould.size());
    Digit d=mould[c];
    return d;
}

//���ź�������digitList������������ʹdigitList�����������Ӷ�����Ϳɫ�������
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

//���»���xλ�õ�d�߿飬������check����
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
//������ɫ�ȣ���ȡ��ǰ��ȱ�ٵ���ɫ
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

//��������ȣ���һ��С�߿������ɫ��������ɫ�����µ��������
void DigitMananger::drawOneDigltColor(int i)
{
    int t=getNeedColor();
    if(t!=-1){
        digitList[i].setColor(colorList[t]);
        areas[t]+=digitList[i].num;
        areas[colorList.size()-1]-=digitList[i].num;
    }
}
//��ȡ������check�����е�λ��
int DigitMananger::getMatX(int x)
{
    return x+300;
}

int DigitMananger::getMatY(int y)
{
    return y+300;
}
//��С�ߵ��x,y������С�ߵ�λ���Ǹ�С�߿���
int DigitMananger::getDigitLocal(int x, int y)
{
    if(getMatX(x)<0||getMatX(x)>601||getMatY(y)<0||getMatY(y)>601)return -1;
    return check[getMatY(y)][getMatX(x)];
}
//��ȡС�߿��б�
vector<Digit> DigitMananger::getDigitList()
{
    return digitList;
}
