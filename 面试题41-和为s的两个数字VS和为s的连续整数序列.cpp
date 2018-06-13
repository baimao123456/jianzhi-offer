
/*************************************/
//和为s的两个数字 VS 和为s的连续整数序列
/*************************************/
#include <iostream>
#include <vector>
using namespace std;
//和为s的两个数字
bool FindNumberWithSum(vector<int>data, int sum, int& num1, int& num2)
{
    bool found = false;
    int length = data.size();

    if(length < 1)
        return found;

    int start = 0;
    int end = length - 1;

    while(start < end)
    {
        int curSum = data[start] + data[end];
        if(curSum == sum)               //找到两个值的和等于sum
        {
            num1 = data[start];         //满足和的两个值
            num2 = data[end];
            cout << "the two number :  "<< num1 << ',' << num2;
            found = true;
            break;
        }
        else if(curSum > sum)
            end--;
        else
            start++;
    }
    return found;
}
//打印smll 到 big 的连续序列
void PrintContinuousSequence(int small, int big)
{
    for(int i = small ; i <= big; i++)
        cout << i << ',';
    cout << endl;
}
//和为sum的连续整数序列
void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return;

    int small = 1, big = 2;
    int middle = (1 + sum) >> 1;
    int curSum = small + big;

    while(small < middle) //这里设置small < middle,是因为如果small大于middle，small+big肯定会大于sum
    {
        if(curSum == sum)
            PrintContinuousSequence(small, big);

        while(curSum > sum && small < middle)  //如果当前的和大于sum，则减去small，直到满足条件
        {
            curSum -= small;                   //cursum太大了，就减去small
            small++;

            if(curSum == sum)
                PrintContinuousSequence(small, big);
        }
        big++;
        curSum += big;
    }
}
int main(void)
{
    vector<int> number = {1,2,4,7,11,15};
    int num1 = 0,num2 = 0;
    bool found = FindNumberWithSum(number, 15, num1, num2);
    cout << "the two number that sum is 15:  "<< num1 << "  ,  " << num2 << endl;

    FindContinuousSequence(15);
    return 0;
}
