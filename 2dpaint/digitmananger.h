#ifndef DIGITMANANGER_H
#define DIGITMANANGER_H
#include<vector>
#include"digit.h"
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<ctime>
using namespace std;
class DigitMananger
{
private:
    //mould ��������������ļ��ж�����digit
    vector<Digit>mould;
    //digitList�����������ѡ���digit�б�,��Ҫ������Ļ��ȥ��digit
    vector<Digit>digitList;

    //��mould�л�ȡһ�������digit
    Digit getRandomDigit();
    //��digitList�е�Ԫ�ؽ����������
    void randomSort();
public:
    DigitMananger();
    //��ʼ��ȫ��
    void initAll();
    //��(xs-xe)(ys-ye)�ľ������Զ����digit
    void addDigitToRect(int xs,int ys,int xe,int ye);


};

#endif // DIGITMANANGER_H
