/**************************/
//判断字符串是否能表示数值
/**************************/
#include <iostream>

using namespace std;
void scanDigits(char** str)  //这里要对指针进行操作，所以要用指针的指针
{
    while(**str != '\0' && **str >= '0' && **str <= '9') //找到所有的int型数值
        ++(*str);
}
bool isExponential(char** str)
{
    if(**str != 'e' && **str != 'E') //如果不是e也不是E，则不是科学计数法
        return false;

    ++(*str);
    if(**str == '+' || **str == '-')
        ++(*str);

    if(**str == '\0')
        return false;

    scanDigits(str);          //e或E后边必须接 int 型数
    return (**str == '\0') ? true : false; //如果整数后边没有其他字符，就是指数型，如果有其他的字符，就不是
}
bool isNumeric(char* str)
{
    if(str == NULL)
        return false;

    if(*str == '+' || *str == '-')
        ++str;
    if(*str == '\0')              //仅有符号，没有数字同样不是数值
        return false;

    bool numeric = true;         //先标志 能表示数值

    scanDigits(&str);
    if(*str != '\0')
    {
        //继续判断小数
        if(*str == '.')
        {
            ++str;
            scanDigits(&str);  //继续扫描小数后面的数字
            if(*str == 'e' || *str == 'E')
                numeric = isExponential(&str);
        }
        else if(*str == 'e' || *str == 'E') //也可能没有浮点数
            numeric = isExponential(&str);
        else
            numeric = false;
    }
    return numeric && *str == '\0';    //如果字符串全部检测完，则返回numeric的值，若没有检测完，说明不能表示数值
}
int main()
{
    cout << isNumeric("-123456789.123456789E-123456789a") << endl;
    return 0;
}

