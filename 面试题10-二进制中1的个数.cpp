/**********************************/
//��������1�ĸ���
/**********************************/
#include <iostream>
using namespace std;
//��������1�ĸ���,ѭ������Ϊn������n��int���ͣ�����Ҫѭ��32��
int NumberOf1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}
//�Ƚ��������1�ĸ���
int NumberOf1_Best(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n = (n -1) & n;  //n-1�������ұߵ�1���ұߵ�0���1��ԭ����1���0
        //��ʱ��n�к��е�1�ĸ�������٣�ֱ��n=0
    }
    return count;
}
int main()
{
    cout << "hello world" << endl;
    cout << NumberOf1(-100) << endl;
    cout << NumberOf1_Best(-100) << endl;
    return 0;
}
