
/*************************************/
//反转字符串 VS 左旋转字符串
/*************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//反转整个句子
char* ReverseSentence(char* pData, int length)
{
    if(pData == NULL)
        return NULL;

    char* start = pData;
    char* end = pData;

    reverse(pData, pData + 15);

    while(*end != '\0')         //依次将句子中的单词反转
    {
        if(*end == ' ')         //如果遇见空格，就反转一个单词
        {
            reverse(start, end);
            start = end + 1;
        }
        end++;
    }
    return pData;
}
//左旋转字符串,,"abcdefg" sizeof()会计算最后的 '\0',length会计算成8，实际是7
char* LeftRotateString(char* pStr, int n, int length)
{
    if(pStr != NULL && n >= 0)
    {
        char* start = pStr;
        reverse(start, start + n);              //反转前面的字符

        reverse(start + n,start + length - 1);  //反转后面的字符

        reverse(start,start + length - 1);      //将整个句子反转
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

    //左旋 2 位
    char str2[] = "abcdefg";
    cout << str2 << endl;
    cout << LeftRotateString(str2, 2, sizeof(str2)) << endl;

    return 0;
}
