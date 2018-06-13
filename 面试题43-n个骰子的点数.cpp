/*************************************/
//n个骰子的点数
/*************************************/
#include <iostream>
#include <algorithm>
using namespace std;
/*
int g_maxValue = 6;            //骰子的面数，这里是 6

void Probability(int original, int current, int sum, int* pProbabilities)
{
    if(current == 1)
        pProbabilities[sum - original]++;
    else
        for(int i = 1; i <= g_maxValue; ++i)  //计算从1到6的每一种点数和剩下的n-1个骰子的点数和
            Probability(original, current - 1, i + sum, pProbabilities);
}
// 该函数用来计算 number 个骰子所有点数和出现的次数
// number是骰子的个数,pProbabilities用来存放骰子所有值出现的次数，进而计算概率
void Probability(int number, int* pProbabilities)
{
    for(int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, pProbabilities);
}
void PrintProbability(int number)
{
    if(number < 1)
        return;

    int maxSum = number * g_maxValue;            //点数和最大值
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = 1; i <= maxSum; ++i)
        pProbabilities[i - number] = 0;          //因为点数和至少是 n，所以这里数组的大小为 maxSum - number

    Probability(number, pProbabilities);         //计算number个骰子的各种点数和出现的次数

    int total = pow((double)g_maxValue, number); //一共有total种点数和情况

    for(int i = number; i <= maxSum; ++i)        //计算每种情况出现的概率
    {
        double ratio = (double)pProbabilities[i - number] / total;
        //printf("%d: %e\n", i, ratio);
    }

    delete[] pProbabilities;
}*/
//递归解法
//思路：设n个骰子某次投掷点数和为s的出现次数是F(n, s)，
//那么，F(n, s)等于n - 1个骰子投掷的点数和为 s - 1、s - 2、s - 3、s -4、s - 5、s - 6时的次数的总和：
//F(n,s)=F(n-1,s-1)+F(n-1,s-2)+F(n-1,s-3)+F(n-1,s-4)+F(n-1,s-5)+F(n-1,s-6)
//计算number个骰子某次投掷点数和为sum的出现次数
int CountNumber(int number, int sum)
{
    if(sum < number || sum > 6 * number)
        return 0;

    if(number == 1)
        return 1;
    else
        return CountNumber(number - 1,sum - 6) + CountNumber(number - 1,sum - 5) + CountNumber(number - 1,sum - 4)
                +CountNumber(number - 1,sum - 3) + CountNumber(number - 1,sum - 2) + CountNumber(number - 1,sum - 1);
}
void PrintProbability(int n)
{
    int i=0;
    unsigned int nTotal = pow((double)6, n);
    for(i = n; i <= 6 * n; i++)
        printf("P(s=%d) = %d/%d\n", i, CountNumber(n,i), nTotal);
    cout << endl;
}
/********************************************/
//循环法
/********************************************/
int main(void)
{
    PrintProbability(2);
    return 0;
}
