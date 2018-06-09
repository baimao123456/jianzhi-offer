
/************************************/
//����min������ջ,�ÿռ任ʱ��
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
    if(m_min.size() == 0 || value < m_min.top())   //���m_min��û��Ԫ�أ�����valueС��m_min����Сֵ��
        m_min.push(value);                         //����m_min�е���Сֵ
    else
        m_data.push(m_min.top());
}
template<class T> void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0); //��֤m_data��m_min��Ϊ��
    m_data.pop();                                  //����Ԫ��
    m_min.pop();
}
template<class T> const T&  StackWithMin<T>::min()const
{
    assert(m_data.size() > 0 && m_min.size() > 0); //��֤m_data��m_min��Ϊ��
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
