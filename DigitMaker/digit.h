#ifndef DIGIT_H
#define DIGIT_H
#include<QColor>
#include<iostream>

/*
    工具类，记录要画在画布上的小版块的相关属性
*/
class Digit
{
private:
    int l;//数码小块矩阵的长
    int w;//数码小块矩阵的宽
    int xp;//左上角第一个元素的x坐标
    int yp;//左上角第一个元素的y坐标
    QColor color;//小块的颜色



public:
    bool mat[15][15];//数码小块矩阵
    int num;//小块中非零元素的个数
    int getLength();
    int getWidth();
    int getNum();
    //设置数码小块左上角的点的坐标
    void setLocation(int x,int y);
    //获取坐标
    int getLocationX();
    int getLocationY();
    //设置与获取颜色
    QColor getColor();
    void setColor(QColor color);
    void print();
    //获取矩阵
//    void getMat(bool**mat);
    Digit(int l,int w,bool mat1[10][10],int num);

    Digit();
};

#endif // DIGIT_H
