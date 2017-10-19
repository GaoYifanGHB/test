#ifndef DIGIT_H
#define DIGIT_H
#include<QColor>

class Digit
{
private:
    int l;//����С�����ĳ�
    int w;//����С�����Ŀ�
    bool mat[10][10];//����С�����
    int num;//С���з���Ԫ�صĸ���
    QColor color;//С�����ɫ

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
