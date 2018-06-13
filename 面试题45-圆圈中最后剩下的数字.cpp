
/*************************************/
//圆圈中最后剩下的数字
/*************************************/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
//环状链表法
int LastRemaining(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    unsigned int i = 0;

    list<int> numbers;
    for(int i = 0; i < n ;i++)    //依次将数据放到链表中去
        numbers.push_back(i);

    list<int>::iterator current = numbers.begin();
    while(numbers.size() > 1)     //如果链表中剩下一个数，退出循环，否则一直删除
    {
        for(int i = 1; i < m; ++i)    //current指向第三个元素
        {
            current++;
            if(current == numbers.end())
                current = numbers.begin();
        }
        list<int>::iterator next = ++ current; //指向删除节点的下一个，同样需要判断是否到了链表末尾
        if(next == numbers.end())
            next = numbers.begin();
        --current;
        numbers.erase(current);
        current = next;
    }
    return *(current);
}
//公式法--循环
int LastRemaining2(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    int last = 0;
    for(int i = 2; i <= n;i++)
        last = (last + m) % i;

    return last;
}
//公式法--递归
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
