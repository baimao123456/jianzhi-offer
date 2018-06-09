/**********************************/
//数值的整数次方
/**********************************/
#include <iostream>
using namespace std;
bool g_InvalidInput = false;   //定义bool变量，用来记录是否是有效的输入
//判断两个小数是否相等
bool equal(double num1,double num2)
{
    if((num1 - num2 > - 0.0000001)&&
       (num1 - num2 <   0.0000001))
        return true;
    else
        return false;
}
//求
double PowerWithUnsignedExponent(double base,int exponent)
{
    /*
    double result = 1.0;
    for(int i = 1;i <= exponent;++i)
        result *= base;
    */
    //改进版本，高效
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    //递归求乘方
    double result = PowerWithUnsignedExponent(base,exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1) //如果exponent是奇数
        result *= base;
    return result;
}
//计算base的exponent次方
double Power(double base,int exponent)
{
    g_InvalidInput = false;

    if(equal(base,0.0) && exponent < 0)  //如果base为0，且exponent小于0，则输出错误
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(exponent); //求幂系数的绝对值
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);

    double result = PowerWithUnsignedExponent(base,absExponent); //计算base的absExponent（正数）次方
    if(exponent < 0)  //如果是负幂，则输出倒数
        result = 1 / result;
    return result;
}
int main()
{
    cout << "hello world" << endl;
    cout << Power(-2.0,-3) << endl;
    return 0;
}

