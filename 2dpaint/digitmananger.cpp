#include "digitmananger.h"

DigitMananger::DigitMananger()
{
    initAll();
}
//初始化，主要功能是
//1.从所有文件中读出的digit赋值给mould
//2.清空digitList
void DigitMananger::initAll()
{
    ifstream fs;
    stringstream ss;
    string filename;
    allArea=0;
    this->mould.clear();
    this->colorList.clear();
    this->digitList.clear();
    this->ratio.clear();
    this->areas.clear();
    memset(check,-1,sizeof(check));
    for(int i=1;i<=5;i++){
        ss<<i;
        ss>>filename;
        ss.clear();
        filename="./mat/"+filename+".txt";
        fs.open(filename.c_str(),ios::in);
        cout << filename << endl;
        int l,w;
        fs>>l>>w;
        int num=0;
        bool mat[10][10];
        for(int i=0;i<l;i++){
            for(int j=0;j<w;j++){
                fs>>mat[i][j];
                if(mat[i][j])num++;
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        filename="";
        fs.close();
        Digit d(l,w,mat,num);
        this->mould.push_back(d);
    }
}



void DigitMananger::addDigitToRect(int xs, int ys, int xe, int ye)
{
    srand(time(NULL));
    int l=ye-ys+1,w=xe-xs+1;
    allArea+=l*w;
    cout<<xs<<" "<<ys<<" "<<xe<<" "<<ye<<endl;
    //    cout << l << " " << w << endl;
    for(int i=getMatY(ys);i<=getMatY(ye);i++){
        for(int j=getMatX(xs);j<=getMatX(xe);j++){
            check[i][j]=-1;
        }
    }
    int tx=0,ty=0;
    for(int y=ys;y<=ye;y+=ty){
        ty=0;
        for(int x=xs;x<=xe;x+=tx){
            Digit d=getRandomDigit();
            d.setLocation(x,y);
            adjustDigit(d,xs,ys,xe,ye);
            digitList.push_back(d);
            tx=d.getWidth()/2;
            if(ty<d.getLength())ty=d.getLength();
        }
        ty/=2;
    }
}

void DigitMananger::setColorList(vector<QColor> cL)
{
    this->colorList=cL;

}

void DigitMananger::setColorRatio(vector<int> r)
{
    this->ratio=r;
    for(int i=0;i<colorList.size();i++){
        cout<<ratio[i]<<" ";
    }
    cout<<endl;
}

void DigitMananger::drawAllDigltColor()
{
    randomSort();
    //初始化当前各颜色面积
    for(int i=0;i<colorList.size()-1;i++){
        areas.push_back(0);
    }
    areas.push_back(allArea);
    for(int i=0;i<digitList.size();i++){
        drawOneDigltColor(i);
    }
    //    for(int i=0;i<areas.size();i++){
    //        cout<<areas[i]<<" ";
    //    }
    //    cout<<endl;

}

void DigitMananger::printCheck(int xs, int ys, int xe, int ye)
{
    //    cout<<"printCheck"<<endl;

    for(int i=getMatY(ys);i<=getMatY(ye);i++){
        for(int j=getMatX(xs);j<=getMatX(xe);j++){
            cout<<setw(4)<<check[i][j];
        }
        cout<<endl;
    }
    cout<<getMatX(xs)<<" "<<getMatY(ys)<<" "<<getMatX(xe)<<" "<<getMatY(ye)<<endl;

}


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
    for(int k=0;k<digitList.size();k++){
        Digit d= digitList[k];
        for(int i=0;i<d.getLength();i++){
            for(int j=0;j<d.getWidth();j++){
                if(d.mat[i][j]){
                    check[getMatY(i+d.getLocationY())][getMatX(j+d.getLocationX())]=k;
                }
            }
        }
    }
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

int DigitMananger::getNeedColor()
{
    int x=-1;
    int y=-1;
    for(int i=0;i<ratio.size();i++){
        int t=areas[i]/ratio[i];
        cout<<t<<" ";
        if(y==-1){
            y = t;x=i;
        }else if(y>t){
            y=t;x=i;
        }
    }
    cout<<endl;
    cout<<x<<endl;
    return x;
}

void DigitMananger::drawOneDigltColor(int i)
{

    int t=getNeedColor();
    if(t!=-1){
        digitList[i].setColor(colorList[t]);
        areas[t]+=digitList[i].num;
        areas[colorList.size()-1]-=digitList[i].num;
    }
}

int DigitMananger::getMatX(int x)
{
    return x+300;
}

int DigitMananger::getMatY(int y)
{
    return y+300;
}

int DigitMananger::getDigitLocal(int x, int y)
{
    cout<<getMatX(x)<<" ---- "<<getMatY(y)<<endl;
    return check[getMatY(y)][getMatX(x)];
}

vector<Digit> DigitMananger::getDigitList()
{
    return digitList;
}
