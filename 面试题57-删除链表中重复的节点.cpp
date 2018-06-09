/*************************************/
//删除链表中重复的节点
/*************************************/
#include <iostream>
#include "List.h"
using namespace std;
template<class T>
ListNode<T>* DeleteDuplication(ListNode<T>* pHead)
{
    if(pHead == NULL)
        return pHead;

    ListNode<T>* pPreNode = NULL;    //当前节点的前一个节点
    ListNode<T>* pCurNode = pHead;   //当前节点
    ListNode<T>* pNextNode = NULL;   //当前节点的后一个节点

    while(pCurNode != NULL)          //依次判断整个链表
    {
        //如果当前节点存在后节点，且两个节点的值相同，此时就是重复的，需要判断一共重复了几个
        if(pCurNode->pNext != NULL && pCurNode->value == pCurNode->pNext->value)
        {
            pNextNode = pCurNode->pNext;

            //找到全部的重复节点
            while(pNextNode != NULL && pNextNode->pNext != NULL
                  && pNextNode->pNext->value == pCurNode->value)
            {
                pNextNode = pNextNode->pNext;
            }
            if(pCurNode == pHead)        //如果头结点就是重复的，则更新头结点
                pHead = pNextNode->pNext;
            else
                pPreNode->pNext = pNextNode->pNext; //如果头结点不重复，则重新连接链表
            pCurNode = pNextNode->pNext;            //继续判断后边的节点
        }
        else
        {
            pPreNode = pCurNode;
            pCurNode = pCurNode->pNext;
        }
    }
    return pHead;
}
int main()
{
    ListNode<int>* pNode1 = new ListNode<int>(1);
    ListNode<int>* pNode2 = new ListNode<int>(2);
    ListNode<int>* pNode3 = new ListNode<int>(3);
    ListNode<int>* pNode4 = new ListNode<int>(3);
    ListNode<int>* pNode5 = new ListNode<int>(4);
    ListNode<int>* pNode6 = new ListNode<int>(4);
    ListNode<int>* pNode7 = new ListNode<int>(5);
    ConnectNode(pNode1, pNode2);
    ConnectNode(pNode2, pNode3);
    ConnectNode(pNode3, pNode4);
    ConnectNode(pNode4, pNode5);
    ConnectNode(pNode5, pNode6);
    ConnectNode(pNode6, pNode7);

    show(pNode1);
    ListNode<int>* root = DeleteDuplication(pNode1);
    show(root);
    return 0;
}




