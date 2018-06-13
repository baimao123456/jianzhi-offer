
/*************************************/
//��ת�ַ��� VS ����ת�ַ���
/*************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//��ת��������
char* ReverseSentence(char* pData, int length)
{
    if(pData == NULL)
        return NULL;

    char* start = pData;
    char* end = pData;

    reverse(pData, pData + 15);

    while(*end != '\0')         //���ν������еĵ��ʷ�ת
    {
        if(*end == ' ')         //��������ո񣬾ͷ�תһ������
        {
            reverse(start, end);
            start = end + 1;
        }
        end++;
    }
    return pData;
}
//����ת�ַ���,,"abcdefg" sizeof()��������� '\0',length������8��ʵ����7
char* LeftRotateString(char* pStr, int n, int length)
{
    if(pStr != NULL && n >= 0)
    {
        char* start = pStr;
        reverse(start, start + n);              //��תǰ����ַ�

        reverse(start + n,start + length - 1);  //��ת������ַ�

        reverse(start,start + length - 1);      //���������ӷ�ת
        return pStr;
    }
    else
    {
        cout << "error input";
    }
}
int main(void)
{
    char str[] = "I am a student.";
    cout << str << endl;
    cout << ReverseSentence(str, sizeof(str)) << endl;

    //���� 2 λ
    char str2[] = "abcdefg";
    cout << str2 << endl;
    cout << LeftRotateString(str2, 2, sizeof(str2)) << endl;

    return 0;
}
