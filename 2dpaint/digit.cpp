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

QColor Digit::getColor()
{
    return this->color;
}

void Digit::setColor(QColor color)
{
    this->color=color;
}

bool **Digit::getMat()
{
    return this->mat;
}

Digit::Digit(int l, int w, bool mat[][], int num)
{
    this->l=l;
    this->w=w;
    this->mat=mat;
    this->num=num;
    this->color=QColor(0,0,0);
}
