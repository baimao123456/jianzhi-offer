/*************************************/
//n�����ӵĵ���
/*************************************/
#include <iostream>
#include <algorithm>
using namespace std;
/*
int g_maxValue = 6;            //���ӵ������������� 6

void Probability(int original, int current, int sum, int* pProbabilities)
{
    if(current == 1)
        pProbabilities[sum - original]++;
    else
        for(int i = 1; i <= g_maxValue; ++i)  //�����1��6��ÿһ�ֵ�����ʣ�µ�n-1�����ӵĵ�����
            Probability(original, current - 1, i + sum, pProbabilities);
}
// �ú����������� number ���������е����ͳ��ֵĴ���
// number�����ӵĸ���,pProbabilities���������������ֵ���ֵĴ����������������
void Probability(int number, int* pProbabilities)
{
    for(int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, pProbabilities);
}
void PrintProbability(int number)
{
    if(number < 1)
        return;

    int maxSum = number * g_maxValue;            //���������ֵ
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = 1; i <= maxSum; ++i)
        pProbabilities[i - number] = 0;          //��Ϊ������������ n��������������Ĵ�СΪ maxSum - number

    Probability(number, pProbabilities);         //����number�����ӵĸ��ֵ����ͳ��ֵĴ���

    int total = pow((double)g_maxValue, number); //һ����total�ֵ��������

    for(int i = number; i <= maxSum; ++i)        //����ÿ��������ֵĸ���
    {
        double ratio = (double)pProbabilities[i - number] / total;
        //printf("%d: %e\n", i, ratio);
    }

    delete[] pProbabilities;
}*/
//�ݹ�ⷨ
//˼·����n������ĳ��Ͷ��������Ϊs�ĳ��ִ�����F(n, s)��
//��ô��F(n, s)����n - 1������Ͷ���ĵ�����Ϊ s - 1��s - 2��s - 3��s -4��s - 5��s - 6ʱ�Ĵ������ܺͣ�
//F(n,s)=F(n-1,s-1)+F(n-1,s-2)+F(n-1,s-3)+F(n-1,s-4)+F(n-1,s-5)+F(n-1,s-6)
//����number������ĳ��Ͷ��������Ϊsum�ĳ��ִ���
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
//ѭ����
/********************************************/
int main(void)
{
    PrintProbability(2);
    return 0;
}
