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
    void adjustDigit(Digit &d,int xs,int ys,int xe,int ye);

    //该矩阵用来记录图中每个点对应小数码块的位置，判断矩阵生成的小数码块是否存在重合，该矩阵使得屏幕支持的最大分辨率为600*600
    //生成窗口的中点(0,0)需与矩阵的中点(300,300)对齐
    int check[610][610];
    //整个图的面积
    int allArea;
    //计算最缺少的颜色
    int getNeedColor();
    //对当前块涂色
    void drawOneDigltColor(int i);
    //获取在check矩阵中坐标
    int getMatX(int x);
    int getMatY(int y);


public:
    //根据相对坐标获取一个数码块在digitList中的位置
    int getDigitLocal(int x,int y);
    //digitList用来保存随机选择的digit列表,即要画到屏幕上去的digit
    vector<Digit>digitList;
    vector<Digit> getDigitList();
    //交换digitList中两个元素
    void swapDigit(int i1,int i2);
    //根据第n块小方块调整其他变量
    void rebuildDigit(Digit d,int n);
    DigitMananger();
    //初始化全部
    void initAll();
    //在(xs-xe)(ys-ye)的矩形中自动添加digit
    void addDigitToRect(int xs,int ys,int xe,int ye);

    //重新生成check
    void rebulidCheck();

    //设置颜色图的颜色
    void setColorList(vector<QColor> cL);
    //设置每种颜色对应的比例
    void setColorRatio(vector<int> r);
    //对所有的数码涂色
    void drawAllDigltColor();
    //测试用,输出check矩阵
    void printCheck(int xs,int ys,int xe,int ye);


};

#endif // DIGITMANANGER_H
