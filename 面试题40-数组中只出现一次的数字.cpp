/*************************************/
//������ֻ����һ�ε�����
/*************************************/
#include <iostream>
#include <vector>
using namespace std;
//�ж�num�ĵ�indexBitλ�Ƿ���1
bool IsBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}
//���������ҵ�num�е�һ��Ϊ1��λ�ã����λ������������һ�β�һ���ĵط�
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
//������ֻ����һ�ε�����
void FindNumsAppearOnce(vector<int> data, int& num1, int& num2)
{
    if(data.size() < 2)
        return ;
    int resultExclusiveOR = 0;               //������ȫ�������Ľ��
    for(int i = 0;i < data.size(); i++)
        resultExclusiveOR ^= data[i];

    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);  //���Ľ���е�һ��1��λ�ã������������������ͬ����

    num1 = num2 = 0;

    for(int j = 0; j < data.size(); j++)    //�������ֱַ������ͬ�������Ϊ0���������ʣ�µ��������Ǹ���ͬ����
    {
        if(IsBit1(data[j], indexOf1))       //���data[j]��indexOf1λ����1,�൱�ڽ�����ֳ������֣�������ֵͬ�ֲ��ڲ�ͬ����
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
