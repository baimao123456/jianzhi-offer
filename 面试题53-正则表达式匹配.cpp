/**************************/
//正则表达式匹配
/**************************/
#include <iostream>

using namespace std;
bool matchCore(char* str, char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*') //如果下一个字符是*，则有多种状态
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
        {
            return matchCore(str + 1, pattern + 2)  //匹配*之前的字符一次
                || matchCore(str + 1, pattern)      //保持pattern不变，匹配*之前的字符多次
                || matchCore(str, pattern + 2);      // *之前的字符匹配0次
        }
        else
        {
            return matchCore(str, pattern + 2);     //如果*之前的字符和str不匹配，则忽略 *的作用，匹配pattern的*之后的字符
        }
    }
    //如果当前字符匹配或者pattern的当前字符是‘.’，继续匹配下一个
    if(*pattern == *str || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}
bool match(char* str, char* pattern)
{
    if(str == NULL || pattern == nullptr)
        return false;
    return matchCore(str, pattern);
}
int main()
{
    cout << match("abaca","ab*ac*a") << endl;
    return 0;
}

