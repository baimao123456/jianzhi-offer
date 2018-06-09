/*********************************/
//��ת����
/*********************************/
#include<iostream>
#include"List.h"
using namespace std;

//��ת����
template<class T>
ListNode<T>* ReverseList(ListNode<T>* pHead)
{
    ListNode<T>* pReversedHead = NULL;     //��ת֮���ͷ���
    ListNode<T>* pNode = pHead;            //�������������еĽڵ�
    ListNode<T>* pPrev = NULL;             //֮ǰ�Ľڵ�
    while(pNode != NULL)
    {
        ListNode<T>* pNext = pNode->pNext; //������һ���ڵ�

        if(pNext == NULL)               //�����β�ڵ㣬��ת֮���β������ԭ����ͷ���
            pReversedHead = pNode;

        pNode->pNext = pPrev;           //֮ǰ�Ľڵ���Ϊ��ǰ�ڵ�ĺ�ڵ�
        pPrev = pNode;                  //����ǰ�ڵ�
        pNode = pNext;                  //ָ����һ���ڵ�
    }

    return pReversedHead;               //���ط�ת֮���ͷ���
}
//��ת����--�ݹ�
template<class T>
ListNode<T>* ReverseListRecursively(ListNode<T>* pHead)
{
    if(pHead == NULL || pHead->pNext == NULL)  //�������Ϊ�ջ�����β�ڵ㣬�򷵻�
        return pHead;

    ListNode<T>* pReversedHead = ReverseListRecursively(pHead->pNext); //�ҵ���ת֮����µ�ͷ���,һֱѭ��������β��

    pHead->pNext->pNext = pHead;//�����pHead->pNext��β�ڵ㣬pHead��β�ڵ��ǰ�ڵ�
    pHead->pNext = NULL;        //����������Ҫ�������γɱջ�

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

