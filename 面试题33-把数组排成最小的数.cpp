/**********************************/
//把数组排成最小的数
/**********************************/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>
using namespace std;

int compare(const void* strNumber1, const void* strNumber2);

const int g_MaxNumberLength = 10;          //最大数据长度

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];  //开辟能存储合并字符串的空间
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

//打印数组nember中的数字所能构成的最小数
void PrintMinNumber(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        return;

    char** strNumbers = (char**)(new int[length]);     //指向char*型指针的指针,相当于二维数组
    for(int i = 0; i < length; ++i)                    //将数组中的int型数据转换成字符串
    {
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }

    qsort(strNumbers, length, sizeof(char*), compare); //对数组内的字符串进行排序，排序规则是compare

    for(int i = 0; i < length; ++i)                    //将排序后的字符串打印输出
        printf("%s", strNumbers[i]);
    printf("\n");

    for(int i = 0; i < length; ++i)                    //释放开辟的空间
        delete[] strNumbers[i];
    delete[] strNumbers;
}
// 如果[strNumber1][strNumber2] > [strNumber2][strNumber1], 返回值大于0
// 如果[strNumber1][strNumber2] = [strNumber2][strNumber1], 返回值等于0
// 如果[strNumber1][strNumber2] < [strNumber2][strNumber1], 返回值小于0
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
//简化版本  c++
/*****************************************************/
//比较函数，，按照返回1进行排序，比如 a_str < b_str,则  a_str排在b_str前边
int cmp(int a, int b)
{
    string a_str = to_string(a) + to_string(b);
    string b_str = to_string(b) + to_string(a);

    return a_str < b_str;
}
//打印数组nember中的数字所能构成的最小数
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

    //简化版本
    vector<int> numbers2(numbers,numbers + sizeof(numbers)/sizeof(int));
    PrintMinNumber(numbers2);
    return 0;
}
