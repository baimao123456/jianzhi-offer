/*************************************/
//쳲���������
/*************************************/
#include<iostream>
using namespace std;
/*******************************/
//�������,��1+2+3+...+n
/*******************************/
//�ݹ���
int AddFrom1ToN_Recursive(int n)
{
    return n <= 0 ? 0 : n + AddFrom1ToN_Recursive(n - 1);
}
//������
int AddFrom1ToN_Iterative(int n)
{
    int result = 0;
    for(int i = 1;i <= n;i++)
        result += i;
    return result;
}
//쳲��������У�1,1,2,3,5��...��--�ݹ�
long long Fibonacci_Recursive(unsigned int n)
{
    if(n < 0)     //ע��n = 0ʱ�����1��
        return 0;
    if(n <= 1)
        return 1;
    return Fibonacci_Recursive(n-1) + Fibonacci_Recursive(n-2);
}
//쳲��������У�1,1,2,3,5��...��--����
long long Fibonacci_Iterative(unsigned int n)
{
    if(n <= 1)
        return 1;
    long long  num_old = 1;
    long long  num_new = 2;
    long long result = 0;
    for(int i = 2;i < n;i++)
    {
        result = num_old + num_new;
        num_old = num_new;
        num_new = result;
    }
    return result;
}
int main()
{
    cout << "hello world" << endl;
    cout << AddFrom1ToN_Recursive(30) << endl;
    cout << AddFrom1ToN_Iterative(30) << endl;
    cout << Fibonacci_Recursive(5) << endl;
    cout << Fibonacci_Iterative(5) << endl;
    return 0;
}
