/*************************************/
//��1+2+...+n,�����ó˳�����ѭ�����ж����
/*************************************/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
//*******************************************
//���ù��캯�����
//*******************************************
class Temp
{

public:
    Temp() { ++N ; Sum += N;}
    static void Reset() { N = 0; Sum = 0;}
    static unsigned int GetSum() { return Sum;}

private:
    static unsigned int N;
    static unsigned int Sum;
};
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;
unsigned int Sum_Solution1(unsigned int n)
{
    Temp::Reset();

    Temp* a = new Temp[n];
    delete[] a;
    a = NULL;

    return Temp::GetSum();
}
//*******************************************
//�����麯�����
//*******************************************
class A;
A* Array[2];
class A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};
class B : public A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n]->Sum(n - 1) + n;  //���nΪ0�򷵻�0��ͨ��n��ѡ�������ĸ��麯��
    }
};
unsigned int Sum_Solution2(unsigned int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    return Array[1]->Sum(n);
}
//*******************************************
//���ú���ָ�����
//*******************************************
typedef unsigned int (*fun)(unsigned int);    //����һ������ָ������

unsigned int Solution3_Teminator(unsigned int n);
unsigned int Sum_Solution3(unsigned int n);

static fun f[2] = {Solution3_Teminator, Sum_Solution3}; //�����ڱ�����Ǻ����ĵ�ַ

unsigned int Solution3_Teminator(unsigned int n)
{
    return 0;
}
unsigned int Sum_Solution3(unsigned int n)
{
    return n + f[!!n](n - 1);
}

//*******************************************
//����ģ���������
//*******************************************
template <unsigned int n> struct Sum_Solution4
{
    enum Value { N = Sum_Solution4<n - 1>::N + n};
};
template <> struct Sum_Solution4<1>
{
    enum Value { N = 1};
};
int main(void)
{

    cout << Sum_Solution1(3) << endl;
    cout << Sum_Solution2(3) << endl;
    cout << Sum_Solution3(3) << endl;
    cout << Sum_Solution4<3>::N << endl;
    return 0;
}
