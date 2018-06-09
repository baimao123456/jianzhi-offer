//List����
#ifndef List_
#define List_
#include <iostream>
#include "ListNode.h"

using namespace std;

//������β�����һ���ڵ�
template<class T>
void AddToTail(ListNode<T>** pHead,T value)
{
    ListNode<T> *pNew = new ListNode<T>(value);  //�½�һ���ڵ㣬�����ٿռ�
    //pNew->value = value;
    //pNew->pNext = NULL;

    if(*pHead == NULL)                //���pHead�ǿսڵ㣬���Ҫ��ӵĽڵ���ΪpHead
        *pHead = pNew;
    else                              //�ҵ���������һ���ڵ�
    {
        ListNode<T>* pNode = *pHead;
        while(pNode->pNext != NULL)   //���pNode->pnext��NULL��˵������ڵ�������һ��
            pNode = pNode->pNext;
        pNode->pNext = pNew;          //������ֱ�ӶԽڵ���и�ֵ
    }
}
//ɾ����һ������value�Ľڵ�
template<class T>
void RemoveNode(ListNode<T>** pHead,T value)
{
    if(*pHead == NULL || pHead == NULL)
        return;
    ListNode<T>* pToBeDeleted = NULL;
    if((*pHead)->value == value)         //���ͷ������Ҫɾ���Ľڵ�
    {
        pToBeDeleted = *pHead;           //��Ҫɾ���Ľڵ�� pToBeDeleted
        *pHead = (*pHead)->pNext;        //����ͷ���
    }
    else
    {
        ListNode<T>* pNode = *pHead;
        while((pNode->pNext != NULL)&&(pNode->pNext->value != value))  //���pNode->next�������һ���ڵ㣬��û���ҵ�����value�Ľڵ㣬��һֱ����
            pNode = pNode->pNext;         //��ʱ��pNode����Ҫɾ���ڵ��ǰһ���ڵ�
        if(pNode->pNext != NULL && pNode->pNext->value == value) //����ҵ���һ������value�Ľڵ㣬�Ҳ������һ���ڵ�
        {
            pToBeDeleted = pNode->pNext;        //��Ҫɾ���Ľڵ�� pToBeDeleted
            pNode->pNext = pNode->pNext->pNext; //���½�������
        }
        if(pToBeDeleted != NULL)          //����ҵ��˷��������Ľڵ㣬��ɾ��
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
//��ӡ����Ľڵ�
template<class T>
void show(ListNode<T> *pHead)
{
    ListNode<T>* pNode = pHead;
    while(pNode != NULL)   //���pNode->pnext��NULL��˵������ڵ�������һ��
    {
        cout << pNode->value << ',';
        pNode = pNode->pNext;
    }
    cout << endl;
}
#endif // List_
