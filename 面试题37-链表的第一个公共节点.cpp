/**************************************/
//����ĵ�һ�������ڵ�
/**************************************/
#include <iostream>
#include <vector>
#include "List.h"
using namespace std;
//�ҵ���һ�������ڵ�
ListNode<int>* FindFirstCommonNode(ListNode<int>* pHead1, ListNode<int>* pHead2)
{
    ListNode<int>* p1 = pHead1;
    ListNode<int>* p2 = pHead2;

    //ͬ����Ҫ�������Σ���һ��������������Ĳ�ֵ���ڶ����ҹ�����
    while(p1 != p2)
    {
        p1 = (p1 == NULL ? pHead2 : p1->pNext);
        p2 = (p2 == NULL ? pHead1 : p2->pNext);
        cout << (p1->value) << ',' << (p2->value) << endl;mm
    }
    return p1;
}
int main()
{
    ListNode<int>* pNode1 = new ListNode<int>(1);
    ListNode<int>* pNode2 = new ListNode<int>(2);
    ListNode<int>* pNode3 = new ListNode<int>(3);
    ListNode<int>* pNode4 = new ListNode<int>(4);
    ListNode<int>* pNode5 = new ListNode<int>(5);
    ListNode<int>* pNode6 = new ListNode<int>(6);
    ListNode<int>* pNode7 = new ListNode<int>(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    show(pNode1);
    show(pNode4);

    cout << FindFirstCommonNode(pNode1,pNode4)->value << endl;
    return 0;
}
