/******************************/
//打印1到最大的n位数
/******************************/
#include <iostream>
#include <string.h>
using namespace std;
int count = 0;
//字符串递增加1
bool Increment(char *number)
{
    bool isOverflow = false;              //最高位是否进位标志
    int nTakeOver = 0;
    int nLength = strlen(number);         //字符串的长度

    for(int i = nLength - 1;i >= 0;i--)   //遍历每1位
    {
        int nSum = number[i] - '0' + nTakeOver;  //依次取各个位上的值再加上进位，

        if(i == nLength - 1)              //如果是数字的个位，则nSum++
            nSum++;

        if(nSum >= 10)                    //如果产生进位，则for继续循环，给次高位进位
        {
            if(i == 0)                    //最高位有进位
                isOverflow = true;
            else
            {
                nSum -= 10;          //低位清0
                nTakeOver = 1;       //产生进位
                number[i] = '0' + nSum;  //低位变成0
            }
        }
        else
        {
            number[i] = '0' + nSum;  //如果nsum不大于10，则直接在该位上增加，然后直接退出打印
            break;
        }
    }
    return isOverflow;
}
//从非0的地方开始打印
void PrintNumber(char *number)
{
    bool isBeginning0 = true;              //标志是否以0开头
    int nLength = strlen(number);          //数字的长度
    for(int i = 0;i < nLength;i++)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if(!isBeginning0)
            cout << number[i];
    }
    cout << endl;
}
//打印从1到N的数,用加1的方法
/*void Print1ToMaxofNDigits(int n)
{
    if(n <= 0)
        return;

    char *number = new char[n + 1];       //创建一个用来保存数字的字符串
    memset(number,'0',n);                 //将字符串number的每个元素初始化为'0'
    number[n] = '\0';                     //字符串的最后一位是'\0'
    while(!Increment(number))             //如果最高位没有产生进位，则一直增加，并打印
    {
        PrintNumber(number);              //每增加1，就打印
    }
    delete[] number;                      //释放number空间
}*/
/*****************************************/
//利用全排列来打印1到N的数字
/*****************************************/
void Print1ToMaxofNDigitsRecursively(char *number,int length,int index)
{
    if(index == length - 1)               //如果已经设置好数字的最后一位
    {
        PrintNumber(number);              //打印数字
        return;
    }
    for(int i = 0;i < 10;i++)             //
    {
        number[index + 1] = i + '0';      //次低位进行全排列
        Print1ToMaxofNDigitsRecursively(number,length,index + 1);  //每位上生成 1-9
    }

}
//利用从高位到低位的全排列来递归生成数字
void Print1ToMaxofNDigits(int n)
{
    if(n <= 0)
        return;

    char *number = new char[n + 1];       //创建一个用来保存数字的字符串
    number[n] = '\0';                     //字符串的最后一位是'\0'

    for(int i = 0;i < 10;++i)             //最高位产生 1-0排列
    {
        number[0] = i + '0';             //用来设置最高位的值，最小是1，最大是9
        Print1ToMaxofNDigitsRecursively(number,n,0);
    }
    delete[] number;                      //释放number空间
}
int main()
{
    cout << "hello world" << endl;

    Print1ToMaxofNDigits(100);
    /*char *number1 = new char[2 + 1];       //创建一个用来保存数字的字符串
    number1[3] = '\0';                     //字符串的最后一位是'\0'
    number1[0] = 0 + '0';
    Print1ToMaxofNDigitsRecursively(number1,3,0);*/
    return 0;
}

