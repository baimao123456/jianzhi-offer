/*******************************************/
//从1到n整数中1出现的次数
/*******************************************/
#include <iostream>
#include <string.h>
using namespace std;
//计算10的n次方
int PowerBase10(unsigned int n)
{
    int result = 1;
    for(unsigned int i = 0;i < n;++i)
        result *= 10;
    return result;
}
//统计字符串中 1 的个数
int NumberOf1(const char* strN)
{
    if(!strN || *strN < '0'|| *strN > '9' || *strN == '\n')
        return 0;
    int first = *strN - '0';   //首先取最高位的数字

    //static_cast相当于传统的C语言里的强制转换
    unsigned int length = static_cast<unsigned int>(strlen(strN));  //获取字符串的长度
    if(length == 1 && first == 0)    //如果最后的个位是0，说明没有1
        return 0;
    if(length == 1 &&first > 0)      //如果最后的个位大于0，说明存在1
        return 1;

    //假设strN是“21345”
    //numFirstDigit是数字10000-19999的第一个位中的数目
    //numFirstDigit是只出现在最高位上的个数
    int numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = PowerBase10(length - 1);  //如果最高位大于1，因为每位是 0 - 9，所以这里用幂
    else if(first == 1)
        numFirstDigit = atoi(strN + 1) + 1;       //如果最高位等于1，则1出现在最高位的个数为 除去最高位的个数 + 1

    //numOtherDigits 是 1346~‘2’1345除了最高位之外的数位中 1 的数目
    int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
    //numRecursive是 1~1345 中的数目
    int numRecursive = NumberOf1(strN + 1);       //迭代计算 1 的个数

    return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Between1AndN(int n)
{
    if(n <= 0)
        return 0;
    char strN[50];             //用来存储数字的每一位
    sprintf(strN, "%d", n);    //将数字转化成字符串

    return NumberOf1(strN);    //返回 1 的个数
}
int main(void)
{
    cout << "hello world" << endl;
    cout << NumberOf1Between1AndN(21);
    return 0;
}
