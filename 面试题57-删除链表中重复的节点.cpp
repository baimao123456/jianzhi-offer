/*************************************/
//ɾ���������ظ��Ľڵ�
/*************************************/
#include <iostream>
#include "List.h"
using namespace std;
template<class T>
ListNode<T>* DeleteDuplication(ListNode<T>* pHead)
{
    if(pHead == NULL)
        return pHead;

    ListNode<T>* pPreNode = NULL;    //��ǰ�ڵ��ǰһ���ڵ�
    ListNode<T>* pCurNode = pHead;   //��ǰ�ڵ�
    ListNode<T>* pNextNode = NULL;   //��ǰ�ڵ�ĺ�һ���ڵ�

    while(pCurNode != NULL)          //�����ж���������
    {
        //�����ǰ�ڵ���ں�ڵ㣬�������ڵ��ֵ��ͬ����ʱ�����ظ��ģ���Ҫ�ж�һ���ظ��˼���
        if(pCurNode->pNext != NULL && pCurNode->value == pCurNode->pNext->value)
        {
            pNextNode = pCurNode->pNext;

            //�ҵ�ȫ�����ظ��ڵ�
            while(pNextNode != NULL && pNextNode->pNext != NULL
                  && pNextNode->pNext->value == pCurNode->value)
            {
                pNextNode = pNextNode->pNext;
            }
            if(pCurNode == pHead)        //���ͷ�������ظ��ģ������ͷ���
                pHead = pNextNode->pNext;
            else
                pPreNode->pNext = pNextNode->pNext; //���ͷ��㲻�ظ�����������������
            pCurNode = pNextNode->pNext;            //�����жϺ�ߵĽڵ�
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




