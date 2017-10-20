#include "digitmananger.h"

DigitMananger::DigitMananger()
{
}
//初始化，主要功能是
//1.从所有文件中读出的digit赋值给mould
//2.清空digitList
void DigitMananger::initAll()
{
    ofstream fs;
    stringstream ss;
    string filename;
    for(int i=0;i<60;i++){
        ss<<i;
        ss>>filename;
        ss.flush();
        filename="./mat/"+filename+".txt";
        fs.open(filename.c_str(),ios::in);
        int l,w;
        fs>>l>>w;
        int num=0;
        bool mat[10][10];
        for(int i=0;i<l;i++){
            for(int j=0;j<w;j++){
                fs>>mat[i][j];
                if(mat[i][j])num++;
            }
        }
        filename="";
        fs.close();
        Digit d(l,w,mat,num);
        this->mould.push_back(d);
    }
}
