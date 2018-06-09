/*************************************/
//������7-������ջʵ�ֶ���
/*************************************/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//���������
template<class T> class cQueue
{
public:
    cQueue(void){size = 0;}  //���캯��
    ~cQueue(void){} //��������
    int size;
    void appendTail(const T& element);  //�ڶ�β����һ��Ԫ��
    T deleteHead();                  //ɾ����ͷԪ��
    void show_queue();               //������ӡԪ��
private:
    stack<T> stack1;   //��������ջ�����洢Ԫ��
    stack<T> stack2;
};
//�����ڶ�β����һ��Ԫ��
template<class T> void cQueue<T>::appendTail(const T& element)
{
    stack1.push(element);  //��elementѹ��ջ1
    size++;                //���г��ȼ�1
}
//ɾ����ͷԪ��
template<class T> T cQueue<T>::deleteHead()
{
    if(stack2.empty()) //���stack2�ǿ�ջ����stack1�е�����ѹ��stack2�У�˳��ᵹ����
    {
        while(!stack1.empty())
        {
            T& data = stack1.top();  //��stack1��ջ��Ԫ������ѹ��Stack2��
            stack1.pop();            //ɾ��stack1ջ��Ԫ��
            stack2.push(data);
        }
    }
    if(stack2.empty())              //���Stack2Ϊ�գ�˵������û��Ԫ��
        cout << "queue is empty()" << endl;
    T head = stack2.top();          //stack2�е�ջ��Ԫ�ؾ���stack1�е�ջ��Ԫ�أ�Ҳ���Ƕ���ͷ
    stack2.pop();
    size--;
    return head;  //���ض���ͷ
}
//�������У����δ�ӡ
template<class T> void cQueue<T>::show_queue()
{
    stack<T> stack3;
    //
    while(!stack2.empty())       //�ȴ�ӡstack2�е�Ԫ��
    {
        cout << stack2.top() << ',';
        stack2.pop();
    }
    while(!stack1.empty())
    {
        T& data = stack1.top();  //��stack1��ջ��Ԫ������ѹ��Stack2��
        stack1.pop();            //ɾ��stack1ջ��Ԫ��
        stack3.push(data);
    }
    while(!stack3.empty())       //�ȴ�ӡstack2�е�Ԫ��
    {
        cout << stack3.top() << ',';
        stack3.pop();
    }
}
/*************************************/
//����������ʵ��ջ
/*************************************/
//����ջ��
template<class T> class cStack
{
public:
    cStack(void){size = 0;}  //���캯��
   ~cStack(void){} //��������
    int size;
    void appendTail(const T& element);  //�ڶ�β����һ��Ԫ��
    T deleteHead();                  //ɾ����ͷԪ��
    void show_stack();               //������ӡԪ��
private:

    queue<T> queue1;   //��������ջ�����洢Ԫ��
    queue<T> queue2;
};
//��elementѹ���ջ
template<class T> void cStack<T>::appendTail(const T& element)
{
    queue1.push(element);
    size++;
}
//��ɾ��ջ��Ԫ�أ���������queue���������ؽ���ѹ�뵯������������±���ӵ�Ԫ��
template<class T> T cStack<T>::deleteHead()
{
    if(queue1.empty() && queue2.empty())
        cout << "stack is empty!" << endl;
    if(!queue1.empty())   //��queue1�е�Ԫ��push��queue2�У���������һ��Ԫ�أ���Ϊɾ����Ԫ��
    {
        while(queue1.size() > 1)  //ȡqueue1�е������ӵ�Ԫ��
        {
            T& data = queue1.front();
            queue2.push(data);
            queue1.pop();
        }
        size--;
        T& data = queue1.front();
        queue1.pop();
        return data;
    }
    if(!queue2.empty())  //��queue2�е�Ԫ��push��queue1�У���������һ��Ԫ�أ���Ϊɾ����Ԫ��
    {
        while(queue2.size() > 1)  //ȡqueue2�е������ӵ�Ԫ��
        {
            T& data = queue2.front();
            queue1.push(data);
            queue2.pop();
        }
        size--;
        T& data = queue2.front();
        queue2.pop();
        return data;
    }
}
int main()
{
    //cqueue  test
    cQueue<int> q;
    q.appendTail(1);
    q.appendTail(3);
    q.appendTail(5);
    q.appendTail(7);
    q.appendTail(9);
    q.deleteHead();
    q.appendTail(4);
    //q.show_queue();
    q.appendTail(2);
    q.appendTail(6);
    q.appendTail(8);
    //q.show_queue();
    while(q.size > 0)  //�������
    {
        cout << q.deleteHead() << ',';
    }
    cout << endl;
    /*********************/
    //cstack test
    cStack<int> s;
    s.appendTail(1);
    s.appendTail(3);
    s.appendTail(5);
    s.appendTail(7);
    s.appendTail(9);
    s.deleteHead();
    s.appendTail(2);
    s.deleteHead();
    s.appendTail(4);
    s.appendTail(6);
    while(s.size > 0)  //�������
    {
        cout << s.deleteHead() << ',';
    }
    cout << endl;
    return 0;
}
