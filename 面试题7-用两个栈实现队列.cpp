/*************************************/
//面试题7-用两个栈实现队列
/*************************************/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//定义队列类
template<class T> class cQueue
{
public:
    cQueue(void){size = 0;}  //构造函数
    ~cQueue(void){} //析构函数
    int size;
    void appendTail(const T& element);  //在队尾插入一个元素
    T deleteHead();                  //删除队头元素
    void show_queue();               //遍历打印元素
private:
    stack<T> stack1;   //定义两个栈用来存储元素
    stack<T> stack2;
};
//定义在队尾插入一个元素
template<class T> void cQueue<T>::appendTail(const T& element)
{
    stack1.push(element);  //将element压入栈1
    size++;                //队列长度加1
}
//删除队头元素
template<class T> T cQueue<T>::deleteHead()
{
    if(stack2.empty()) //如果stack2是空栈，则将stack1中的数据压入stack2中，顺序会倒过来
    {
        while(!stack1.empty())
        {
            T& data = stack1.top();  //将stack1的栈顶元素依次压入Stack2中
            stack1.pop();            //删除stack1栈顶元素
            stack2.push(data);
        }
    }
    if(stack2.empty())              //如果Stack2为空，说明队列没有元素
        cout << "queue is empty()" << endl;
    T head = stack2.top();          //stack2中的栈顶元素就是stack1中的栈底元素，也就是队列头
    stack2.pop();
    size--;
    return head;  //返回队列头
}
//遍历队列，依次打印
template<class T> void cQueue<T>::show_queue()
{
    stack<T> stack3;
    //
    while(!stack2.empty())       //先打印stack2中的元素
    {
        cout << stack2.top() << ',';
        stack2.pop();
    }
    while(!stack1.empty())
    {
        T& data = stack1.top();  //将stack1的栈顶元素依次压入Stack2中
        stack1.pop();            //删除stack1栈顶元素
        stack3.push(data);
    }
    while(!stack3.empty())       //先打印stack2中的元素
    {
        cout << stack3.top() << ',';
        stack3.pop();
    }
}
/*************************************/
//用两个队列实现栈
/*************************************/
//定义栈类
template<class T> class cStack
{
public:
    cStack(void){size = 0;}  //构造函数
   ~cStack(void){} //析构函数
    int size;
    void appendTail(const T& element);  //在队尾插入一个元素
    T deleteHead();                  //删除队头元素
    void show_stack();               //遍历打印元素
private:

    queue<T> queue1;   //定义两个栈用来存储元素
    queue<T> queue2;
};
//将element压入堆栈
template<class T> void cStack<T>::appendTail(const T& element)
{
    queue1.push(element);
    size++;
}
//将删除栈顶元素，利用两个queue对数据来回进行压入弹出，来获得最新被添加的元素
template<class T> T cStack<T>::deleteHead()
{
    if(queue1.empty() && queue2.empty())
        cout << "stack is empty!" << endl;
    if(!queue1.empty())   //将queue1中的元素push到queue2中，仅仅留下一个元素，作为删除的元素
    {
        while(queue1.size() > 1)  //取queue1中的最后被添加的元素
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
    if(!queue2.empty())  //将queue2中的元素push到queue1中，仅仅留下一个元素，作为删除的元素
    {
        while(queue2.size() > 1)  //取queue2中的最后被添加的元素
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
    while(q.size > 0)  //遍历输出
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
    while(s.size > 0)  //遍历输出
    {
        cout << s.deleteHead() << ',';
    }
    cout << endl;
    return 0;
}
