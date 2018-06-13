/**********************************/
//�������ų���С����
/**********************************/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>
using namespace std;

int compare(const void* strNumber1, const void* strNumber2);

const int g_MaxNumberLength = 10;          //������ݳ���

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];  //�����ܴ洢�ϲ��ַ����Ŀռ�
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

//��ӡ����nember�е��������ܹ��ɵ���С��
void PrintMinNumber(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        return;

    char** strNumbers = (char**)(new int[length]);     //ָ��char*��ָ���ָ��,�൱�ڶ�ά����
    for(int i = 0; i < length; ++i)                    //�������е�int������ת�����ַ���
    {
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }

    qsort(strNumbers, length, sizeof(char*), compare); //�������ڵ��ַ��������������������compare

    for(int i = 0; i < length; ++i)                    //���������ַ�����ӡ���
        printf("%s", strNumbers[i]);
    printf("\n");

    for(int i = 0; i < length; ++i)                    //�ͷſ��ٵĿռ�
        delete[] strNumbers[i];
    delete[] strNumbers;
}
// ���[strNumber1][strNumber2] > [strNumber2][strNumber1], ����ֵ����0
// ���[strNumber1][strNumber2] = [strNumber2][strNumber1], ����ֵ����0
// ���[strNumber1][strNumber2] < [strNumber2][strNumber1], ����ֵС��0
int compare(const void* strNumber1, const void* strNumber2)
{
    // [strNumber1][strNumber2]
    strcpy(g_StrCombine1, *(const char**)strNumber1);
    strcat(g_StrCombine1, *(const char**)strNumber2);

    // [strNumber2][strNumber1]
    strcpy(g_StrCombine2, *(const char**)strNumber2);
    strcat(g_StrCombine2, *(const char**)strNumber1);

    //cout << g_StrCombine1 << ' ' << g_StrCombine2 << endl;
    return strcmp(g_StrCombine1, g_StrCombine2);
}
/*****************************************************/
//�򻯰汾  c++
/*****************************************************/
//�ȽϺ����������շ���1�������򣬱��� a_str < b_str,��  a_str����b_strǰ��
int cmp(int a, int b)
{
    string a_str = to_string(a) + to_string(b);
    string b_str = to_string(b) + to_string(a);

    return a_str < b_str;
}
//��ӡ����nember�е��������ܹ��ɵ���С��
void PrintMinNumber(vector<int> numbers)
{
    if(numbers.size() <= 0)
        return;

    sort(numbers.begin(),numbers.end(),cmp);

    for(vector<int>::iterator it = numbers.begin();it != numbers.end(); ++it)
    {
        cout << *it;
    }
    cout << endl;
}

int main()
{
    cout << "hello world" << endl;
    int numbers[] = {32,54,1,8,67,9};
    PrintMinNumber(numbers, sizeof(numbers)/sizeof(int));

    //�򻯰汾
    vector<int> numbers2(numbers,numbers + sizeof(numbers)/sizeof(int));
    PrintMinNumber(numbers2);
    return 0;
}
