
/************************************/
//包含min函数的栈,用空间换时间
/************************************/
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T>
class StackWithMin
{
public:
    void push(const T& value);
    void pop();
    const T& min()const;
private:
    stack<T> m_data;
    stack<T> m_min;
};
template<class T> void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);
    if(m_min.size() == 0 || value < m_min.top())   //如果m_min中没有元素，或者value小于m_min的最小值，
        m_min.push(value);                         //更新m_min中的最小值
    else
        m_data.push(m_min.top());
}
template<class T> void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0); //保证m_data和m_min不为空
    m_data.pop();                                  //弹出元素
    m_min.pop();
}
template<class T> const T&  StackWithMin<T>::min()const
{
    assert(m_data.size() > 0 && m_min.size() > 0); //保证m_data和m_min不为空
    return m_min.top();
}
int main()
{
    StackWithMin<int> t;
    t.push(3);
    cout << "the minest value is :" << t.min() << endl;
    t.push(4);
    cout << "the minest value is :" << t.min() << endl;
    t.push(2);
    cout << "the minest value is :" << t.min() << endl;
    t.push(1);
    cout << "the minest value is :" << t.min() << endl;
    t.pop();
    cout << "the minest value is :" << t.min() << endl;
    t.pop();
    cout << "the minest value is :" << t.min() << endl;
    t.push(0);
    cout << "the minest value is :" << t.min() << endl;
    return 0;
}
