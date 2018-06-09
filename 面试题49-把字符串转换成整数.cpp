#include <iostream>
using namespace std;
//将字符串转成int型
enum Status { kValid = 0, kInvalid};
int g_nSratus = kValid;
//核心代码，考虑正负号
long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;

    while(*digit != '\0')
    {
        if(*digit >= '0' && *digit <= '9')          //如果存在非法字符，则返回0
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0'); //计算转换的数

            if((!minus && num > 0x7fffffff) ||      //数值溢出判断
                 (minus && num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }
    return num;
}
int StrToInt(const char* str)
{
    g_nSratus = kInvalid;
    long long num = 0;

    if(str != NULL && *str != '\0')  //str不为空且*str不在字符串末尾
    {
        bool minus = false;
        if(*str == '+')
            str++;
        else if(*str == '-')
        {
            str++;
            minus = true;
        }
        if(*str != '\0')
        {
            num = StrToIntCore(str, minus);
        }
    }
    return (int)num;
}

int main()
{
    cout << StrToInt("-0123456789") << endl;
    return 0;
}
