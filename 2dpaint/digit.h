#ifndef DIGIT_H
#define DIGIT_H
#include<QColor>

class Digit
{
private:
    int l;//数码小块矩阵的长
    int w;//数码小块矩阵的宽
    bool mat[10][10];//数码小块矩阵
    int num;//小块中非零元素的个数
    QColor color;//小块的颜色

public:
    int getLength();
    int getWidth();
    int getNum();
    QColor getColor();
    void setColor(QColor color);
    bool**getMat();

    Digit(int l,int w,bool mat[][],int num);
    Digit();
};

#endif // DIGIT_H
