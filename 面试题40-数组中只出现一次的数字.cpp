/*************************************/
//数组中只出现一次的数字
/*************************************/
#include <iostream>
#include <vector>
using namespace std;
//判断num的第indexBit位是否是1
bool IsBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}
//从右往左找到num中第一个为1的位置，这个位置是两个数第一次不一样的地方
unsigned int FindFirstBitIs1(int num)
{
    int indexBit = 0;
    while((indexBit & 1) == 0 && (indexBit < 8 * sizeof(int)))
    {
        num = num >> 1;
        ++ indexBit;
    }
    return indexBit;
}
//数组中只出现一次的数字
void FindNumsAppearOnce(vector<int> data, int& num1, int& num2)
{
    if(data.size() < 2)
        return ;
    int resultExclusiveOR = 0;               //数组内全部数异或的结果
    for(int i = 0;i < data.size(); i++)
        resultExclusiveOR ^= data[i];

    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);  //异或的结果中第一个1的位置，用这个来区分两个不同的数

    num1 = num2 = 0;

    for(int j = 0; j < data.size(); j++)    //将两部分分别异或，相同的数异或为0，所以最后剩下的数就是那个不同的数
    {
        if(IsBit1(data[j], indexOf1))       //如果data[j]的indexOf1位上是1,相当于将数组分成两部分，两个不同值分布在不同部分
            num1 ^= data[j];
        else
            num2 ^= data[j];
    }
}
int main(void)
{
    vector<int> number = {2,4,3,6,3,2,5,5};
    int num1,num2;
    FindNumsAppearOnce(number, num1, num2);
    cout << "two appear once number is :";
    cout << num1 << ',' << num2 << endl;
    return 0;
}
