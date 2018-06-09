/*******************************************/
//��1��n������1���ֵĴ���
/*******************************************/
#include <iostream>
#include <string.h>
using namespace std;
//����10��n�η�
int PowerBase10(unsigned int n)
{
    int result = 1;
    for(unsigned int i = 0;i < n;++i)
        result *= 10;
    return result;
}
//ͳ���ַ����� 1 �ĸ���
int NumberOf1(const char* strN)
{
    if(!strN || *strN < '0'|| *strN > '9' || *strN == '\n')
        return 0;
    int first = *strN - '0';   //����ȡ���λ������

    //static_cast�൱�ڴ�ͳ��C�������ǿ��ת��
    unsigned int length = static_cast<unsigned int>(strlen(strN));  //��ȡ�ַ����ĳ���
    if(length == 1 && first == 0)    //������ĸ�λ��0��˵��û��1
        return 0;
    if(length == 1 &&first > 0)      //������ĸ�λ����0��˵������1
        return 1;

    //����strN�ǡ�21345��
    //numFirstDigit������10000-19999�ĵ�һ��λ�е���Ŀ
    //numFirstDigit��ֻ���������λ�ϵĸ���
    int numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = PowerBase10(length - 1);  //������λ����1����Ϊÿλ�� 0 - 9��������������
    else if(first == 1)
        numFirstDigit = atoi(strN + 1) + 1;       //������λ����1����1���������λ�ĸ���Ϊ ��ȥ���λ�ĸ��� + 1

    //numOtherDigits �� 1346~��2��1345�������λ֮�����λ�� 1 ����Ŀ
    int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
    //numRecursive�� 1~1345 �е���Ŀ
    int numRecursive = NumberOf1(strN + 1);       //�������� 1 �ĸ���

    return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Between1AndN(int n)
{
    if(n <= 0)
        return 0;
    char strN[50];             //�����洢���ֵ�ÿһλ
    sprintf(strN, "%d", n);    //������ת�����ַ���

    return NumberOf1(strN);    //���� 1 �ĸ���
}
int main(void)
{
    cout << "hello world" << endl;
    cout << NumberOf1Between1AndN(21);
    return 0;
}
