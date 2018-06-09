/*************************************/
//字符流中第一个不重复的字符
/*************************************/
#include <iostream>
#include "List.h"
using namespace std;
//寻找快(1次移动2个节点)慢指针相遇的节点，这个相遇的节点一定在环内
template<class T>
ListNode<int>* MeetingNode(ListNode<int>* pHead)
{
    if(pHead == NULL)
        return NULL;

    ListNode<int>* pSlow = pHead->pNext;
    if(pSlow == NULL)
        return NULL;

    ListNode<int>* pFast = pSlow->pNext;
    while(pSlow != NULL && pFast != NULL)
    {
        if(pFast == pSlow)
            return pFast;
        pSlow = pSlow->pNext;

        pFast = pFast->pNext;
        if(pFast != NULL)         //防止访问出错，pFast可能是NULL，但是NULL->next不存在
            pFast = pFast->pNext;
    }
    return NULL;
}
//找到环的入口节点
template<class T>
ListNode<int>* EntryNodeOfLoop(ListNode<int>* pHead)
{
    ListNode<int>* meetingNode = MeetingNode<T>(pHead);  //找到环内的一个节点
    if(meetingNode == NULL) //如果不存在环，返回空
        return NULL;

    int nodesInLoop = 1;    //环的节点数
    ListNode<int>* pNode = meetingNode;
    while(pNode->pNext != meetingNode)
    {
        pNode = pNode->pNext;
        ++nodesInLoop;
    }

    pNode = pHead;
    for(int i = 0; i < nodesInLoop;i++)
        pNode = pNode->pNext;

    ListNode<int>* pNode2 = pHead;
    while(pNode != pNode2)
    {
        pNode2 = pNode2->pNext;
        pNode = pNode->pNext;
    }
    return pNode;                //环的入口节点
}
int main()
{
    ListNode<int>* pNode1 = new ListNode<int>(1);
    ListNode<int>* pNode2 = new ListNode<int>(2);
    ListNode<int>* pNode3 = new ListNode<int>(3);
    ListNode<int>* pNode4 = new ListNode<int>(4);
    ListNode<int>* pNode5 = new ListNode<int>(5);
    ListNode<int>* pNode6 = new ListNode<int>(6);

    ConnectNode(pNode1, pNode2);
    ConnectNode(pNode2, pNode3);
    ConnectNode(pNode3, pNode4);
    ConnectNode(pNode4, pNode5);
    ConnectNode(pNode5, pNode6);
    ConnectNode(pNode6, pNode3);

    cout << EntryNodeOfLoop<int>(pNode1)->value;

    return 0;
}



