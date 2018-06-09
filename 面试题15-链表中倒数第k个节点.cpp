/********************************/
//�����еĵ�����k���ڵ�
/********************************/
#include <iostream>
#include "ListNode.h"
using namespace std;
//�ҵ������еĵ�����k���ڵ�
template<class T>
ListNode<T>* FindKthToTail(ListNode<T>* pHead,unsigned int k)
{
    if(pHead == NULL || k <= 0)  //�������Ϊ�ջ���kΪ0��ֱ���˳�
        return NULL;

    ListNode<T>* pAnode = pHead;    //��������ָ�룬����������
    ListNode<T>* pBnode = NULL;

    for(int i = 0;i < k - 1;i++) //����pahead������k-1���ڵ㣬����k-1����������pbhead�����pbhead���ǵ�����k���ڵ�
    {
        if(pAnode->pNext != NULL)
            pAnode =  pAnode->pNext;
        else
            return NULL;
    }
    pBnode = pHead;
    while(pAnode->next != NULL)  //ͬʱ����pAhead��pBhead
    {
        pAnode = pAnode->pNext;
        pBnode = pBnode->pNext;
    }
    return pBnode;
}
/**************************************/
//�����Ŀ
/**************************************/
//��������м�ڵ�
template<class T>
ListNode<T>* FindMidNode(ListNode<T>* pHead)
{
    if(pHead == NULL)
        return NULL;

    ListNode<T>* pAnode = pHead;  //��������ָ�룬����Ѱ���м�ڵ�
    ListNode<T>* pBnode = pHead;

    while(pAnode->pNext != NULL)
    {
        pAnode = pAnode->pNext->pNext;   //a�ڵ�ÿ��������
        pBnode = pBnode->pNext;
    }
    return pBnode;
}
int main()
{
    cout << "hello world" << endl;
    return 0;
}
