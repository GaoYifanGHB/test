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
    //mould ��������������ļ��ж�����digit
    vector<Digit>mould;
    //digitList�����������ѡ���digit�б�,��Ҫ������Ļ��ȥ��digit
    vector<Digit>digitList;
    //��Ҫͼ����ɫ
    vector<QColor>colorList;
    //����ɫ��ռ�ı���
    vector<int> ratio;
    //�м��������¼��ǰÿ����ɫ�����
    vector<int> areas;

    //��mould�л�ȡһ�������digit
    Digit getRandomDigit();
    //��digitList�е�Ԫ�ؽ����������
    void randomSort();
    //�ھ�������ж�digitList��������
    void rebuildDigit(Digit &d,int xs,int ys,int xe,int ye);
    //�þ��������жϾ������ɵ�С������Ƿ�����غ�
    int check[500][500];
    //����ͼ�����
    int allArea;
    //������ȱ�ٵ���ɫ
    int getNeedColor();
//    //�Ե�ǰ��Ϳɫ
    void drawOneDigltColor(int i);

public:
    vector<Digit> getDigitList();
    DigitMananger();
    //��ʼ��ȫ��
    void initAll();
    //��(xs-xe)(ys-ye)�ľ������Զ����digit
    void addDigitToRect(int xs,int ys,int xe,int ye);


    //������ɫͼ����ɫ
    void setColorList(vector<QColor> cL);
    //����ÿ����ɫ��Ӧ�ı���
    void setColorRatio(vector<int> r);
//    //�����е�����Ϳɫ
    void drawAllDigltColor();
    //������
    void printCheck(int xs,int ys,int xe,int ye);


};

#endif // DIGITMANANGER_H
