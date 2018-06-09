/*************************************/
//�ַ����е�һ�����ظ����ַ�
/*************************************/
#include <iostream>
#include "List.h"
using namespace std;
//Ѱ�ҿ�(1���ƶ�2���ڵ�)��ָ�������Ľڵ㣬��������Ľڵ�һ���ڻ���
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
        if(pFast != NULL)         //��ֹ���ʳ���pFast������NULL������NULL->next������
            pFast = pFast->pNext;
    }
    return NULL;
}
//�ҵ�������ڽڵ�
template<class T>
ListNode<int>* EntryNodeOfLoop(ListNode<int>* pHead)
{
    ListNode<int>* meetingNode = MeetingNode<T>(pHead);  //�ҵ����ڵ�һ���ڵ�
    if(meetingNode == NULL) //��������ڻ������ؿ�
        return NULL;

    int nodesInLoop = 1;    //���Ľڵ���
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
    return pNode;                //������ڽڵ�
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



