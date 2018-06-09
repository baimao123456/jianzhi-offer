/*************************************/
//������5-��β��ͷ��ӡ����
/*************************************/
#include<iostream>
#include<stack>
#include "ListNode.h"
using namespace std;

//������β�����һ���ڵ�
template<class T>
void AddToTail(ListNode<T>** pHead,T value)
{
    ListNode<T> *pNew = new ListNode<T>();  //�½�һ���ڵ㣬�����ٿռ�
    pNew->value = value;
    pNew->pNext = NULL;

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
//�ҵ�������k���ڵ�
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
    while(pAnode->pNext != NULL)  //ͬʱ����pAhead��pBhead
    {
        pAnode = pAnode->pNext;
        pBnode = pBnode->pNext;
    }
    return pBnode;
}
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
/*******************************************/
//������5-��β��ͷ��ӡ����
/*******************************************/
template<class T>
void PrintListReversingly_Iteratively(ListNode<T>* pHead)
{
    //���õ�����ʽ������ջ���Ƚ���������ʣ�����ת����
    stack<ListNode<T>*> nodes;
    ListNode<T>* pNode = pHead;
    while(pNode != NULL)      //�����ÿ���ڵ�ѹ����ջ
    {
        nodes.push(pNode);    //ѹջ
        pNode = pNode->pNext;
    }
    while(!nodes.empty())     //���ջ��Ϊ�գ������ν�ջ��Ԫ��ȡ����������
    {
        pNode = nodes.top();  //ȡջ��Ԫ��
        cout << pNode->value << ',';
        nodes.pop();
    }
    cout << endl;
}
template<class T>
void PrintListReversingly_Recursively(ListNode<T>* pHead)
{
    //���õݹ�ķ�ʽ����������ȡ��һ���ڵ㣬ʵ�ֵ���
    if(pHead != NULL)             //������Ϊ��
    {
        if(pHead->pNext != NULL)  //���ֻ��һ���ڵ㣬ֱ�����
            PrintListReversingly_Recursively(pHead->pNext);
        cout << pHead->value << ',';
    }
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
    RemoveNode(&p,5);
    show(p);
    PrintListReversingly_Iteratively(p);
    PrintListReversingly_Recursively(p);

    cout << endl <<"from back the number k node is: "<< FindKthToTail(p,3)->value;
    cout << endl <<"from mid node is: "<< FindMidNode(p)->value << endl;

    return 0;
}
