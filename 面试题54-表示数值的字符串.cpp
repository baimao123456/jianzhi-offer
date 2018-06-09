/**************************/
//�ж��ַ����Ƿ��ܱ�ʾ��ֵ
/**************************/
#include <iostream>

using namespace std;
void scanDigits(char** str)  //����Ҫ��ָ����в���������Ҫ��ָ���ָ��
{
    while(**str != '\0' && **str >= '0' && **str <= '9') //�ҵ����е�int����ֵ
        ++(*str);
}
bool isExponential(char** str)
{
    if(**str != 'e' && **str != 'E') //�������eҲ����E�����ǿ�ѧ������
        return false;

    ++(*str);
    if(**str == '+' || **str == '-')
        ++(*str);

    if(**str == '\0')
        return false;

    scanDigits(str);          //e��E��߱���� int ����
    return (**str == '\0') ? true : false; //����������û�������ַ�������ָ���ͣ�������������ַ����Ͳ���
}
bool isNumeric(char* str)
{
    if(str == NULL)
        return false;

    if(*str == '+' || *str == '-')
        ++str;
    if(*str == '\0')              //���з��ţ�û������ͬ��������ֵ
        return false;

    bool numeric = true;         //�ȱ�־ �ܱ�ʾ��ֵ

    scanDigits(&str);
    if(*str != '\0')
    {
        //�����ж�С��
        if(*str == '.')
        {
            ++str;
            scanDigits(&str);  //����ɨ��С�����������
            if(*str == 'e' || *str == 'E')
                numeric = isExponential(&str);
        }
        else if(*str == 'e' || *str == 'E') //Ҳ����û�и�����
            numeric = isExponential(&str);
        else
            numeric = false;
    }
    return numeric && *str == '\0';    //����ַ���ȫ������꣬�򷵻�numeric��ֵ����û�м���꣬˵�����ܱ�ʾ��ֵ
}
int main()
{
    cout << isNumeric("-123456789.123456789E-123456789a") << endl;
    return 0;
}

