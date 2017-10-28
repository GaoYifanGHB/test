#include "filehandle.h"

FileHandle::FileHandle()
{
    this->filename="fff.txt";
}
//���캯���������ļ���
FileHandle::FileHandle(string filename)
{
    this->filename=filename;
}
//����/��ȡdigitManager
DigitMananger FileHandle::getDigitManager()
{
    return this->dm;
}

void FileHandle::setDigitManager(DigitMananger dm)
{
    this->dm=dm;
}
//����/��ȡ�����
void FileHandle::getSize(int &l, int &w, int &h)
{
    l=this->l;
    w=this->w;
    h=this->h;
}

void FileHandle::setSize(int l, int w, int h)
{
    this->l=l;
    this->h=h;
    this->w=w;
}
//����/��ȡ��ɫ������
void FileHandle::setColorList(vector<QColor>cls, vector<int>rls)
{
    this->cls=cls;
    this->rls=rls;
}

void FileHandle::getColorList(vector<QColor> &cls, vector<int>& rls)
{
    cls=this->cls;
    rls=this->rls;
}
//�����ļ�
void FileHandle::save()
{
    fout.open(this->filename.c_str(),ios::out);
    cout<<"open"+this->filename<<endl;
    saveSize();
    cout<<"saveSize();"<<endl;
    saveColorList();
    cout<<"saveColorList();"<<endl;
    saveDigitList();
    cout<<"saveDigitList();"<<endl;
    fout.close();
    delete fout;
    cout<<"finish"<<endl;
}
//���ļ�
void FileHandle::read()
{
    dm.initAll();
    cout<<"dm.initAll();"<<endl;
    fin.open(filename.c_str(),ios::in);
    cout<<"���ļ���"+filename<<endl;
    readSize();
    cout<<"readSize();"<<endl;
    readColorList();
    cout<<"readColorList();"<<endl;
    readDigitList();
    cout<<"readDigitList();"<<endl;
    cout<<dm.digitList.size()<<endl;
    dm.rebulidCheck();
    cout<<"dm.rebulidCheck();"<<endl;
    fin.close();
    cout<<"finish"<<endl;
    delete fin;
}
//��ȡ�ߴ磨����ߣ�
void FileHandle::saveSize()
{
    fout<<this->l<<" "<<this->w<<" "<<this->h<<endl;
}

void FileHandle::readSize()
{
    fin>>this->l>>this->w>>this->h;
}
//��ȡ��ɫ��������Ϣ
void FileHandle::saveColorList()
{

    fout<<this->cls.size()<<endl;
    for(int i=0;i<this->cls.size();i++){
        QColor color=this->cls[i];
        int r,g,b;
        color.getRgb(&r,&g,&b);
        fout<<r<<" "<<g<<" "<<b<<" "<<this->rls[i]<<endl;
    }
}

void FileHandle::readColorList()
{
    int colorNum;
    fin>>colorNum;
    for(int i=0;i<colorNum;i++){
        int r,g,b,t;
        fin>>r>>g>>b>>t;
        this->cls.push_back(QColor(r,g,b));
        this->rls.push_back(t);
    }
    dm.setColorList(cls);
    dm.setColorRatio(rls);
}

//��ȡС�߿��б�
void FileHandle::saveDigitList()
{
    fout<<this->dm.getDigitList().size()<<endl;
    for(int i=0;i<dm.getDigitList().size();i++){
        Digit d=dm.getDigitList()[i];
        this->saveOneDigit(d);
    }
}
void FileHandle::readDigitList()
{
    int num;
    fin>>num;
    cout<<num<<endl;
    for(int i=0;i<num;i++){
        Digit d=this->readOneDigit();
        dm.digitList.push_back(d);
    }
}
//��ȡ����С��
void FileHandle::saveOneDigit(Digit d)
{
    int r,g,b;
    fout<<d.getLength()<<" "<<d.getWidth()<<endl;
    fout<<d.num<<endl;
    fout<<d.getLocationX()<<" "<<d.getLocationY()<<endl;
    d.getColor().getRgb(&r,&g,&b);
    fout<<r<<" "<<g<<" "<<b<<endl;
    for(int i=0;i<d.getLength();i++){
        for(int j=0;j<d.getWidth();j++){
            fout<<d.mat[i][j]<<" ";
        }
        fout<<endl;
    }
}

Digit FileHandle::readOneDigit()
{
    int l,w,num,x,y,r,g,b;
    bool mat[10][10];
    memset(mat,0,sizeof(mat));
    fin>>l>>w;
    fin>>num;
    fin>>x>>y;
    fin>>r>>g>>b;
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            int x;
            fin>>x;
            if(x!=0&&x!=1)x=0;
            mat[i][j]=x;
        }
    }
    Digit d(l,w,mat,num);
    d.setLocation(x,y);
    d.setColor(QColor(r,g,b));
    return d;
}

