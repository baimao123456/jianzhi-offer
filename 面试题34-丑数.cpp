/****************************************/
// ����
/****************************************/
#include <iostream>
#include <vector>

using namespace std;
/***************************************/
//��һ�ֽⷨ��ʱ��Ч�ʵ�
/***************************************/

bool isUgly(int number)
{
    while(number % 2 == 0)               //����ܱ�2��������numberһֱ��2
        number /= 2;
    while(number % 3 == 0)               //����ܱ�3��������numberһֱ��3
        number /= 3;
    while(number % 5 == 0)               //����ܱ�5��������numberһֱ��5
        number /= 5;
    return (number == 1) ? true : false; //������� number Ϊ1��˵��������ǳ���
}
//��õ�index������
int GetUglyNumber(int index)
{
    if(index <= 0)                       //�����������ֱ�ӷ���
        return 0;

    int number = 0;                      //
    int uglyFound = 0;                   //��־��ǰ���������

    while(uglyFound < index)             //�����������ĿС�� index�������Ѱ����һ��
    {
        ++number;
        if(isUgly(number))               //�ж��Ƿ��ǳ���
        {
            ++uglyFound;
        }
    }
    return number;
}
/***************************************/
//�ڶ��ֽⷨ���ռ任ʱ��
/***************************************/
int GetUglyNumber2(int index)
{
    if(index <= 7)
        return index;

    vector<int> pUglyNumbers(index);     //����һ��sizeΪindex��vector��������ų���
    pUglyNumbers[0] = 1;

    int T2 = 0, T3 = 0, T5 = 0, i;       //T2 T3 T5�ֱ�Ϊ֮ǰ�������� 2��3��5��С�����ĳ���

    for(i = 1; i < index; i++)
    {
        pUglyNumbers[i] = min(min(pUglyNumbers[T2] * 2, pUglyNumbers[T3] * 3), pUglyNumbers[T5] * 5);
        if(pUglyNumbers[i] == pUglyNumbers[T2] * 2)  T2++;  // pUglyNumbers[T2]֮ǰ����*2�϶�С�ڵ�ǰ������
        if(pUglyNumbers[i] == pUglyNumbers[T3] * 3)  T3++;  // ���Բ����ٴ���֮ǰ����
        if(pUglyNumbers[i] == pUglyNumbers[T5] * 5)  T5++;
    }

    return  pUglyNumbers[index - 1];
}
int main(void)
{
    cout << "the ugly number is: " << GetUglyNumber(84)<< endl;
    cout << "the ugly number is: " << GetUglyNumber2(84)<< endl;
}
