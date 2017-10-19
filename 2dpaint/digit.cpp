#include "digit.h"

Digit::Digit()
{
}
int Digit::getLength()
{
    return this->l;
}

int Digit::getWidth()
{
    return this->w;
}

int Digit::getNum()
{
    return this->num;
}

void Digit::setLocation(int x, int y)
{
    this->xp=x;
    this->yp=y;
}

int Digit::getLocationX()
{
    return this->xp;
}

int Digit::getLocationY()
{
    return this->yp;
}

QColor Digit::getColor()
{
    return this->color;
}

void Digit::setColor(QColor color)
{
    this->color=color;
}

void Digit::getMat(bool **mat)
{
    for(int i=0;i<w;i++){
        for(int j=0;j<l;j++){
            mat[i][j]=this->mat[i][j];
        }
    }
}

Digit::Digit(int l, int w, bool** mat,int num)
{
    this->l=l;
    this->w=w;
    this->num=num;
    for(int i=0;i<w;i++){
        for(int j=0;j<l;j++){
            this->mat[i][j]=mat[i][j];
        }
    }
    this->color=QColor(0,0,0);
}
