/**************************/
//������ʽƥ��
/**************************/
#include <iostream>

using namespace std;
bool matchCore(char* str, char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*') //�����һ���ַ���*�����ж���״̬
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
        {
            return matchCore(str + 1, pattern + 2)  //ƥ��*֮ǰ���ַ�һ��
                || matchCore(str + 1, pattern)      //����pattern���䣬ƥ��*֮ǰ���ַ����
                || matchCore(str, pattern + 2);      // *֮ǰ���ַ�ƥ��0��
        }
        else
        {
            return matchCore(str, pattern + 2);     //���*֮ǰ���ַ���str��ƥ�䣬����� *�����ã�ƥ��pattern��*֮����ַ�
        }
    }
    //�����ǰ�ַ�ƥ�����pattern�ĵ�ǰ�ַ��ǡ�.��������ƥ����һ��
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

