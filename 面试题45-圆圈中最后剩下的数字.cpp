
/*************************************/
//ԲȦ�����ʣ�µ�����
/*************************************/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
//��״����
int LastRemaining(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    unsigned int i = 0;

    list<int> numbers;
    for(int i = 0; i < n ;i++)    //���ν����ݷŵ�������ȥ
        numbers.push_back(i);

    list<int>::iterator current = numbers.begin();
    while(numbers.size() > 1)     //���������ʣ��һ�������˳�ѭ��������һֱɾ��
    {
        for(int i = 1; i < m; ++i)    //currentָ�������Ԫ��
        {
            current++;
            if(current == numbers.end())
                current = numbers.begin();
        }
        list<int>::iterator next = ++ current; //ָ��ɾ���ڵ����һ����ͬ����Ҫ�ж��Ƿ�������ĩβ
        if(next == numbers.end())
            next = numbers.begin();
        --current;
        numbers.erase(current);
        current = next;
    }
    return *(current);
}
//��ʽ��--ѭ��
int LastRemaining2(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    int last = 0;
    for(int i = 2; i <= n;i++)
        last = (last + m) % i;

    return last;
}
//��ʽ��--�ݹ�
int LastRemaining3(unsigned int n, unsigned int m)
{
    if(n < 1)
        return 0;
    return (LastRemaining3(n - 1, m) + m) % n;
}
int main(void)
{
    cout << "the last number is : " << LastRemaining(5,3) << endl;
    cout << "the last number is : " << LastRemaining3(5,3) << endl;
    return 0;
}
