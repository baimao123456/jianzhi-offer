//List定义
#ifndef List_
#define List_
#include <iostream>
#include "ListNode.h"

using namespace std;

//在链表尾部添加一个节点
template<class T>
void AddToTail(ListNode<T>** pHead,T value)
{
    ListNode<T> *pNew = new ListNode<T>(value);  //新建一个节点，并开辟空间
    //pNew->value = value;
    //pNew->pNext = NULL;

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
template<class T>
void ConnectNode(ListNode<T> *pNode1,ListNode<T> *pNode2)
{
    pNode1->pNext = pNode2;
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
#endif // List_
