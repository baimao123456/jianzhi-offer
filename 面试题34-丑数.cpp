/****************************************/
// 丑数
/****************************************/
#include <iostream>
#include <vector>

using namespace std;
/***************************************/
//第一种解法，时间效率低
/***************************************/

bool isUgly(int number)
{
    while(number % 2 == 0)               //如果能被2整除，则number一直除2
        number /= 2;
    while(number % 3 == 0)               //如果能被3整除，则number一直除3
        number /= 3;
    while(number % 5 == 0)               //如果能被5整除，则number一直除5
        number /= 5;
    return (number == 1) ? true : false; //如果最终 number 为1，说明这个数是丑数
}
//获得第index个丑数
int GetUglyNumber(int index)
{
    if(index <= 0)                       //如果参数错误，直接返回
        return 0;

    int number = 0;                      //
    int uglyFound = 0;                   //标志当前丑数的序号

    while(uglyFound < index)             //如果丑数的数目小于 index，则继续寻找下一个
    {
        ++number;
        if(isUgly(number))               //判断是否是丑数
        {
            ++uglyFound;
        }
    }
    return number;
}
/***************************************/
//第二种解法，空间换时间
/***************************************/
int GetUglyNumber2(int index)
{
    if(index <= 7)
        return index;

    vector<int> pUglyNumbers(index);     //创建一个size为index的vector，用来存放丑数
    pUglyNumbers[0] = 1;

    int T2 = 0, T3 = 0, T5 = 0, i;       //T2 T3 T5分别为之前的数乘以 2、3、5均小于最大的丑数

    for(i = 1; i < index; i++)
    {
        pUglyNumbers[i] = min(min(pUglyNumbers[T2] * 2, pUglyNumbers[T3] * 3), pUglyNumbers[T5] * 5);
        if(pUglyNumbers[i] == pUglyNumbers[T2] * 2)  T2++;  // pUglyNumbers[T2]之前的数*2肯定小于当前最大丑数
        if(pUglyNumbers[i] == pUglyNumbers[T3] * 3)  T3++;  // 所以不用再处理之前的数
        if(pUglyNumbers[i] == pUglyNumbers[T5] * 5)  T5++;
    }

    return  pUglyNumbers[index - 1];
}
int main(void)
{
    cout << "the ugly number is: " << GetUglyNumber(84)<< endl;
    cout << "the ugly number is: " << GetUglyNumber2(84)<< endl;
}
