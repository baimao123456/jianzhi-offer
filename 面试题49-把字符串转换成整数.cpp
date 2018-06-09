#include <iostream>
using namespace std;
//���ַ���ת��int��
enum Status { kValid = 0, kInvalid};
int g_nSratus = kValid;
//���Ĵ��룬����������
long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;

    while(*digit != '\0')
    {
        if(*digit >= '0' && *digit <= '9')          //������ڷǷ��ַ����򷵻�0
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0'); //����ת������

            if((!minus && num > 0x7fffffff) ||      //��ֵ����ж�
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

    if(str != NULL && *str != '\0')  //str��Ϊ����*str�����ַ���ĩβ
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
