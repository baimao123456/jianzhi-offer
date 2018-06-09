/******************************/
//��ӡ1������nλ��
/******************************/
#include <iostream>
#include <string.h>
using namespace std;
int count = 0;
//�ַ���������1
bool Increment(char *number)
{
    bool isOverflow = false;              //���λ�Ƿ��λ��־
    int nTakeOver = 0;
    int nLength = strlen(number);         //�ַ����ĳ���

    for(int i = nLength - 1;i >= 0;i--)   //����ÿ1λ
    {
        int nSum = number[i] - '0' + nTakeOver;  //����ȡ����λ�ϵ�ֵ�ټ��Ͻ�λ��

        if(i == nLength - 1)              //��������ֵĸ�λ����nSum++
            nSum++;

        if(nSum >= 10)                    //���������λ����for����ѭ�������θ�λ��λ
        {
            if(i == 0)                    //���λ�н�λ
                isOverflow = true;
            else
            {
                nSum -= 10;          //��λ��0
                nTakeOver = 1;       //������λ
                number[i] = '0' + nSum;  //��λ���0
            }
        }
        else
        {
            number[i] = '0' + nSum;  //���nsum������10����ֱ���ڸ�λ�����ӣ�Ȼ��ֱ���˳���ӡ
            break;
        }
    }
    return isOverflow;
}
//�ӷ�0�ĵط���ʼ��ӡ
void PrintNumber(char *number)
{
    bool isBeginning0 = true;              //��־�Ƿ���0��ͷ
    int nLength = strlen(number);          //���ֵĳ���
    for(int i = 0;i < nLength;i++)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if(!isBeginning0)
            cout << number[i];
    }
    cout << endl;
}
//��ӡ��1��N����,�ü�1�ķ���
/*void Print1ToMaxofNDigits(int n)
{
    if(n <= 0)
        return;

    char *number = new char[n + 1];       //����һ�������������ֵ��ַ���
    memset(number,'0',n);                 //���ַ���number��ÿ��Ԫ�س�ʼ��Ϊ'0'
    number[n] = '\0';                     //�ַ��������һλ��'\0'
    while(!Increment(number))             //������λû�в�����λ����һֱ���ӣ�����ӡ
    {
        PrintNumber(number);              //ÿ����1���ʹ�ӡ
    }
    delete[] number;                      //�ͷ�number�ռ�
}*/
/*****************************************/
//����ȫ��������ӡ1��N������
/*****************************************/
void Print1ToMaxofNDigitsRecursively(char *number,int length,int index)
{
    if(index == length - 1)               //����Ѿ����ú����ֵ����һλ
    {
        PrintNumber(number);              //��ӡ����
        return;
    }
    for(int i = 0;i < 10;i++)             //
    {
        number[index + 1] = i + '0';      //�ε�λ����ȫ����
        Print1ToMaxofNDigitsRecursively(number,length,index + 1);  //ÿλ������ 1-9
    }

}
//���ôӸ�λ����λ��ȫ�������ݹ���������
void Print1ToMaxofNDigits(int n)
{
    if(n <= 0)
        return;

    char *number = new char[n + 1];       //����һ�������������ֵ��ַ���
    number[n] = '\0';                     //�ַ��������һλ��'\0'

    for(int i = 0;i < 10;++i)             //���λ���� 1-0����
    {
        number[0] = i + '0';             //�����������λ��ֵ����С��1�������9
        Print1ToMaxofNDigitsRecursively(number,n,0);
    }
    delete[] number;                      //�ͷ�number�ռ�
}
int main()
{
    cout << "hello world" << endl;

    Print1ToMaxofNDigits(100);
    /*char *number1 = new char[2 + 1];       //����һ�������������ֵ��ַ���
    number1[3] = '\0';                     //�ַ��������һλ��'\0'
    number1[0] = 0 + '0';
    Print1ToMaxofNDigitsRecursively(number1,3,0);*/
    return 0;
}

