/********************************/
//链表中的倒数第k个节点
/********************************/
#include <iostream>
#include "ListNode.h"
using namespace std;
//找到链表中的倒数第k个节点
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
    while(pAnode->next != NULL)  //同时遍历pAhead和pBhead
    {
        pAnode = pAnode->pNext;
        pBnode = pBnode->pNext;
    }
    return pBnode;
}
/**************************************/
//相关题目
/**************************************/
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
int main()
{
    cout << "hello world" << endl;
    return 0;
}
