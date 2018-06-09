/********************************
//不用加减乘除做加法
   1101      0110    10100   10000   11000
         --->     --->     --->   --->
   1011      10010   00100   01000   00000
********************************/
#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
    int sum, carry;         //和and进位
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;
    }
    while(num2 != 0);            //直到不产生进位

    return num1;
}
//不使用新的变量交换两个变量的值
void swap_new(int& num1, int& num2)
{
    /*
    利用加法
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    */
    //利用 x和x自身异或为0的特点，可以用来交换两个值
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}
int main()
{
    cout << Add(-0,65536) << endl;
    int num1 = 2, num2 = 5;
    swap_new(num1, num2);
    cout << "after swap the two number is :" << num1 << ',' << num2 << endl;
    return 0;
}
