#ifndef DIGITMANANGER_H
#define DIGITMANANGER_H
#include<vector>
#include"digit.h"
using namespace std;
class DigitMananger
{
private:
    //mould ��������������ļ��ж�����digit
    vector<Digit>mould;
    //digitList�����������ѡ���digit�б�,��Ҫ������Ļ��ȥ��digit
    vector<Digit>digitList;


public:
    DigitMananger();
    //��ʼ��ȫ��
    void initAll();
    //��mould�л�ȡһ�������digit
    Digit getRandomDigit();
    //��(xs-xe)(ys-ye)�ľ������Զ����digit
    void addDigitToRect(int xs,int ys,int xe,int ye);

};

#endif // DIGITMANANGER_H
