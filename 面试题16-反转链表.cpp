/*********************************/
//反转链表
/*********************************/
#include<iostream>
#include"List.h"
using namespace std;

//反转链表
template<class T>
ListNode<T>* ReverseList(ListNode<T>* pHead)
{
    ListNode<T>* pReversedHead = NULL;     //反转之后的头结点
    ListNode<T>* pNode = pHead;            //用来遍历链表中的节点
    ListNode<T>* pPrev = NULL;             //之前的节点
    while(pNode != NULL)
    {
        ListNode<T>* pNext = pNode->pNext; //保存下一个节点

        if(pNext == NULL)               //如果是尾节点，反转之后的尾结点就是原来的头结点
            pReversedHead = pNode;

        pNode->pNext = pPrev;           //之前的节点作为当前节点的后节点
        pPrev = pNode;                  //更新前节点
        pNode = pNext;                  //指向下一个节点
    }

    return pReversedHead;               //返回反转之后的头结点
}
//反转链表--递归
template<class T>
ListNode<T>* ReverseListRecursively(ListNode<T>* pHead)
{
    if(pHead == NULL || pHead->pNext == NULL)  //如果链表为空或者是尾节点，则返回
        return pHead;

    ListNode<T>* pReversedHead = ReverseListRecursively(pHead->pNext); //找到反转之后的新的头结点,一直循环到链表尾部

    pHead->pNext->pNext = pHead;//这里的pHead->pNext是尾节点，pHead是尾节点的前节点
    pHead->pNext = NULL;        //！！！很重要，否则形成闭环

    return pReversedHead;
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

    cout << "after recruisely reverse the list is: " << endl;
    ListNode<int>* p_reverse = ReverseList(p);
    show(p_reverse);

    cout << "after reverse the list is: " << endl;
    show(ReverseList(p_reverse));
    return 0;
}

