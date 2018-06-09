/*************************************/
//字符流中第一个不重复的字符
/*************************************/
#include <iostream>

using namespace std;
char FirstAppearingOnce(char* str)
{
    if(str == NULL)
        return '\0';

    int occurrence[256] = {0};   //存储字符出现的次数
    while(*str != '\0')
        occurrence[*(str++)]++;
    for(int i = 0; i < 256; i++)
    {
        if(occurrence[i] == 1)
        {
            cout << "the first appearing number is : "<< (char)i << endl;
            break;
        }
    }
}
int main()
{
    char str[] = "helloworld";
    FirstAppearingOnce(str);
    return 0;
}


