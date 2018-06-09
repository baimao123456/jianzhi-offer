/**********************************/
//合并两个排序的链表
/**********************************/
#include "list.h"
//合并两个排序的链表--递归,能处理相同的元素
template<class T>
ListNode<T>* Merge_Recursively(ListNode<T>* pHead1,ListNode<T>* pHead2)
{
    if(pHead1 == NULL) //如果链表1为空，不用合并，直接返回链表2
        return pHead2;
    if(pHead2 == NULL) //如果链表2为空，不用合并，直接返回链表1
        return pHead1;

    ListNode<T>* pMergeHead = NULL;   //定义一个合并之后的头结点，是两个链表较小的头结点
    if(pHead1->value <= pHead2->value) //如果链表1的头结点比较小，则由链表1的头结点为合并后的头结点
    {
        pMergeHead = pHead1;
        pMergeHead->pNext = Merge_Recursively(pHead1->pNext,pHead2); //将剩下的元素进行合并
    }
    else if(pHead1->value > pHead2->value)
    {
        pMergeHead = pHead2;
        pMergeHead->pNext = Merge_Recursively(pHead1,pHead2->pNext);
    }
    return pMergeHead;
}
//合并两个有序链表--非递归-能解决遇到相同元素问题
template<class T>
ListNode<T>* Merge_Iteratively(ListNode<T>* pHead1,ListNode<T>* pHead2)
{
    if(pHead1 == NULL)                //如果链表1为空，不用合并，直接返回链表2
        return pHead2;
    if(pHead2 == NULL)                //如果链表2为空，不用合并，直接返回链表1
        return pHead1;

    ListNode<T>* pMergeHead = NULL;       //定义一个合并之后的头结点，是两个链表较小的头结点
    if(pHead1->value < pHead2->value)
    {
        pMergeHead = pHead1;
        pHead1 = pHead1->pNext;
    }
    else
    {
        pMergeHead = pHead2;
        pHead2 = pHead2->pNext;
    }
    ListNode<T>* pNode = pMergeHead;       //定义一个节点来记录合并后的链表的最后一个元素
    while(pHead1 && pHead2)
    {
        if(pHead1->value <= pHead2->value) //如果链表1的头结点比较小，则由链表1的头结点为合并后的头结点
        {
            pNode->pNext = pHead1;
            pHead1 = pHead1->pNext;
        }
        else
        {
            pNode->pNext = pHead2;
            pHead2 = pHead2->pNext;
        }
        pNode = pNode->pNext;
    }
    if(pHead1 == NULL)                    //若有一个链表为空，则将直接连接另一个
        pNode->pNext = pHead2;
    else if(pHead2 == NULL)
        pNode->pNext = pHead1;
    return pMergeHead;                    //返回合并之后的头结点
}
int main()
{
    ListNode<int>* p1 = NULL;
    AddToTail(&p1,1);
    AddToTail(&p1,3);
    AddToTail(&p1,5);
    AddToTail(&p1,7);
    AddToTail(&p1,9);
    AddToTail(&p1,11);
    show(p1);
    ListNode<int>* p2 = NULL;
    AddToTail(&p2,1);
    AddToTail(&p2,3);
    AddToTail(&p2,5);
    AddToTail(&p2,7);
    AddToTail(&p2,9);
    AddToTail(&p2,11);
    show(p2);

    cout << "the merge list is : " << endl;
    show(Merge_Recursively(p1,p2));
    return 0;
}
