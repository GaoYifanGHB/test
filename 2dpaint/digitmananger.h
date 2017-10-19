#ifndef DIGITMANANGER_H
#define DIGITMANANGER_H
#include<vector>
#include"digit.h"
using namespace std;
class DigitMananger
{
private:
    //mould 用来保存从所有文件中读出的digit
    vector<Digit>mould;
    //digitList用来保存随机选择的digit列表,即要画到屏幕上去的digit
    vector<Digit>digitList;


public:
    DigitMananger();
    //初始化全部
    void initAll();
    //在mould中获取一个随机的digit
    Digit getRandomDigit();
    //在(xs-xe)(ys-ye)的矩形中自动添加digit
    void addDigitToRect(int xs,int ys,int xe,int ye);

};

#endif // DIGITMANANGER_H
