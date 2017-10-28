#include "digit.h"

Digit::Digit()
{
}
//获取小斑块的尺寸
int Digit::getLength()
{
    return this->l;
}

int Digit::getWidth()
{
    return this->w;
}
//获取小版块中点的数量
int Digit::getNum()
{
    return this->num;
}
//设置小斑块左上角元素的坐标
void Digit::setLocation(int x, int y)
{
    this->xp=x;
    this->yp=y;
}
//获取元素左上角坐标
int Digit::getLocationX()
{
    return this->xp;
}

int Digit::getLocationY()
{
    return this->yp;
}
//获取与设置小斑块颜色
QColor Digit::getColor()
{
    return this->color;
}

void Digit::setColor(QColor color)
{
    this->color=color;
}

void Digit::print()
{
    for(int i=0;i<this->l;i++){
        for(int j=0;j<this->w;j++){
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
////获取小版块矩阵
//void Digit::getMat(bool **mat)
//{
//    for(int i=0;i<w;i++){
//        for(int j=0;j<l;j++){
//            mat[i][j]=this->mat[i][j];
//        }
//    }
//}
//构造函数，初始化小版块
Digit::Digit(int l, int w, bool mat[10][10],int num)
{
    this->l=l;
    this->w=w;
    this->num=num;
    memset(mat,0,sizeof(mat));
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            if(mat[i][j]!=0&&mat[i][j]!=1)mat[i][j]=0;
            this->mat[i][j]=mat[i][j];
        }
    }
    this->color=QColor(0,0,0);
}
