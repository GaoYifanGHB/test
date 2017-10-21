#ifndef DIGITMANANGER_H
#define DIGITMANANGER_H
#include<vector>
#include"digit.h"
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
class DigitMananger
{
private:
    //mould 用来保存从所有文件中读出的digit
    vector<Digit>mould;
    //digitList用来保存随机选择的digit列表,即要画到屏幕上去的digit
    vector<Digit>digitList;
    //需要图的颜色
    vector<QColor>colorList;
    //各颜色所占的比例
    vector<int> ratio;
    //中间变量，记录当前每种颜色的面积
    vector<int> areas;

    //在mould中获取一个随机的digit
    Digit getRandomDigit();
    //对digitList中的元素进行随机重排
    void randomSort();
    //在矩阵过程中对digitList进行修正
    void rebuildDigit(Digit &d,int xs,int ys,int xe,int ye);
    //该矩阵用来判断矩阵生成的小数码块是否存在重合
    int check[500][500];
    //整个图的面积
    int allArea;
    //计算最缺少的颜色
    int getNeedColor();
//    //对当前块涂色
    void drawOneDigltColor(int i);

public:
    vector<Digit> getDigitList();
    DigitMananger();
    //初始化全部
    void initAll();
    //在(xs-xe)(ys-ye)的矩形中自动添加digit
    void addDigitToRect(int xs,int ys,int xe,int ye);


    //设置颜色图的颜色
    void setColorList(vector<QColor> cL);
    //设置每种颜色对应的比例
    void setColorRatio(vector<int> r);
//    //对所有的数码涂色
    void drawAllDigltColor();
    //测试用
    void printCheck(int xs,int ys,int xe,int ye);


};

#endif // DIGITMANANGER_H
