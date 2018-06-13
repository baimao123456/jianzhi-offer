
/*************************************/
//��Ϊs���������� VS ��Ϊs��������������
/*************************************/
#include <iostream>
#include <vector>
using namespace std;
//��Ϊs����������
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
        if(curSum == sum)               //�ҵ�����ֵ�ĺ͵���sum
        {
            num1 = data[start];         //����͵�����ֵ
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
//��ӡsmll �� big ����������
void PrintContinuousSequence(int small, int big)
{
    for(int i = small ; i <= big; i++)
        cout << i << ',';
    cout << endl;
}
//��Ϊsum��������������
void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return;

    int small = 1, big = 2;
    int middle = (1 + sum) >> 1;
    int curSum = small + big;

    while(small < middle) //��������small < middle,����Ϊ���small����middle��small+big�϶������sum
    {
        if(curSum == sum)
            PrintContinuousSequence(small, big);

        while(curSum > sum && small < middle)  //�����ǰ�ĺʹ���sum�����ȥsmall��ֱ����������
        {
            curSum -= small;                   //cursum̫���ˣ��ͼ�ȥsmall
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
