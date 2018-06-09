/*************************************/
//面试题5-从尾到头打印链表
/*************************************/
#include<iostream>
#include<stack>
#include "ListNode.h"
using namespace std;

//在链表尾部添加一个节点
template<class T>
void AddToTail(ListNode<T>** pHead,T value)
{
    ListNode<T> *pNew = new ListNode<T>();  //新建一个节点，并开辟空间
    pNew->value = value;
    pNew->pNext = NULL;

    if(*pHead == NULL)                //如果pHead是空节点，则把要添加的节点作为pHead
        *pHead = pNew;
    else                              //找到链表的最后一个节点
    {
        ListNode<T>* pNode = *pHead;
        while(pNode->pNext != NULL)   //如果pNode->pnext是NULL，说明这个节点就是最后一个
            pNode = pNode->pNext;
        pNode->pNext = pNew;          //这里是直接对节点进行赋值
    }
}
//删除第一个含有value的节点
template<class T>
void RemoveNode(ListNode<T>** pHead,T value)
{
    if(*pHead == NULL || pHead == NULL)
        return;
    ListNode<T>* pToBeDeleted = NULL;
    if((*pHead)->value == value)         //如果头结点就是要删除的节点
    {
        pToBeDeleted = *pHead;           //将要删除的节点给 pToBeDeleted
        *pHead = (*pHead)->pNext;        //更新头结点
    }
    else
    {
        ListNode<T>* pNode = *pHead;
        while((pNode->pNext != NULL)&&(pNode->pNext->value != value))  //如果pNode->next不是最后一个节点，且没有找到包含value的节点，则一直查找
            pNode = pNode->pNext;         //此时的pNode是所要删除节点的前一个节点
        if(pNode->pNext != NULL && pNode->pNext->value == value) //如果找到了一个包含value的节点，且不是最后一个节点
        {
            pToBeDeleted = pNode->pNext;        //将要删除的节点给 pToBeDeleted
            pNode->pNext = pNode->pNext->pNext; //重新进行连接
        }
        if(pToBeDeleted != NULL)          //如果找到了符合条件的节点，则删除
        {
            delete pToBeDeleted;
            pToBeDeleted = NULL;
        }
    }
}
//找到倒数第k个节点
template<class T>
ListNode<T>* FindKthToTail(ListNode<T>* pHead,unsigned int k)
{
    if(pHead == NULL || k <= 0)  //如果链表为空或者k为0，直接退出
        return NULL;

    ListNode<T>* pAnode = pHead;    //定义两个指针，来遍历链表
    ListNode<T>* pBnode = NULL;

    for(int i = 0;i < k - 1;i++) //先让pahead来遍历k-1个节点，保持k-1距离来遍历pbhead，最后pbhead就是倒数第k个节点
    {
        if(pAnode->pNext != NULL)
            pAnode =  pAnode->pNext;
        else
            return NULL;
    }
    pBnode = pHead;
    while(pAnode->pNext != NULL)  //同时遍历pAhead和pBhead
    {
        pAnode = pAnode->pNext;
        pBnode = pBnode->pNext;
    }
    return pBnode;
}
//求链表的中间节点
template<class T>
ListNode<T>* FindMidNode(ListNode<T>* pHead)
{
    if(pHead == NULL)
        return NULL;

    ListNode<T>* pAnode = pHead;  //定义两个指针，用来寻找中间节点
    ListNode<T>* pBnode = pHead;

    while(pAnode->pNext != NULL)
    {
        pAnode = pAnode->pNext->pNext;   //a节点每次走两个
        pBnode = pBnode->pNext;
    }
    return pBnode;
}

//打印链表的节点
template<class T>
void show(ListNode<T> *pHead)
{
    ListNode<T>* pNode = pHead;
    while(pNode != NULL)   //如果pNode->pnext是NULL，说明这个节点就是最后一个
    {
        cout << pNode->value << ',';
        pNode = pNode->pNext;
    }
    cout << endl;
}
/*******************************************/
//面试题5-从尾到头打印链表
/*******************************************/
template<class T>
void PrintListReversingly_Iteratively(ListNode<T>* pHead)
{
    //采用迭代方式，利用栈的先进后出的性质，来翻转链表
    stack<ListNode<T>*> nodes;
    ListNode<T>* pNode = pHead;
    while(pNode != NULL)      //逐个将每个节点压进堆栈
    {
        nodes.push(pNode);    //压栈
        pNode = pNode->pNext;
    }
    while(!nodes.empty())     //如果栈不为空，则依次将栈顶元素取出，并弹出
    {
        pNode = nodes.top();  //取栈顶元素
        cout << pNode->value << ',';
        nodes.pop();
    }
    cout << endl;
}
template<class T>
void PrintListReversingly_Recursively(ListNode<T>* pHead)
{
    //采用递归的方式，不断来读取下一个节点，实现倒序
    if(pHead != NULL)             //若链表不为空
    {
        if(pHead->pNext != NULL)  //如果只有一个节点，直接输出
            PrintListReversingly_Recursively(pHead->pNext);
        cout << pHead->value << ',';
    }
}
int main()
{
    ListNode<int>* p = NULL;
    AddToTail(&p,1);
    AddToTail(&p,3);
    AddToTail(&p,5);
    AddToTail(&p,7);
    AddToTail(&p,9);
    AddToTail(&p,2);
    show(p);
    RemoveNode(&p,5);
    show(p);
    PrintListReversingly_Iteratively(p);
    PrintListReversingly_Recursively(p);

    cout << endl <<"from back the number k node is: "<< FindKthToTail(p,3)->value;
    cout << endl <<"from mid node is: "<< FindMidNode(p)->value << endl;

    return 0;
}
