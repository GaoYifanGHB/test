#include "digit.h"

Digit::Digit()
{
}
//��ȡС�߿�ĳߴ�
int Digit::getLength()
{
    return this->l;
}

int Digit::getWidth()
{
    return this->w;
}
//��ȡС����е������
int Digit::getNum()
{
    return this->num;
}
//����С�߿����Ͻ�Ԫ�ص�����
void Digit::setLocation(int x, int y)
{
    this->xp=x;
    this->yp=y;
}
//��ȡԪ�����Ͻ�����
int Digit::getLocationX()
{
    return this->xp;
}

int Digit::getLocationY()
{
    return this->yp;
}
//��ȡ������С�߿���ɫ
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
////��ȡС������
//void Digit::getMat(bool **mat)
//{
//    for(int i=0;i<w;i++){
//        for(int j=0;j<l;j++){
//            mat[i][j]=this->mat[i][j];
//        }
//    }
//}
//���캯������ʼ��С���
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
