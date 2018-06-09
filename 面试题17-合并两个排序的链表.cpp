/**********************************/
//�ϲ��������������
/**********************************/
#include "list.h"
//�ϲ��������������--�ݹ�,�ܴ�����ͬ��Ԫ��
template<class T>
ListNode<T>* Merge_Recursively(ListNode<T>* pHead1,ListNode<T>* pHead2)
{
    if(pHead1 == NULL) //�������1Ϊ�գ����úϲ���ֱ�ӷ�������2
        return pHead2;
    if(pHead2 == NULL) //�������2Ϊ�գ����úϲ���ֱ�ӷ�������1
        return pHead1;

    ListNode<T>* pMergeHead = NULL;   //����һ���ϲ�֮���ͷ��㣬�����������С��ͷ���
    if(pHead1->value <= pHead2->value) //�������1��ͷ���Ƚ�С����������1��ͷ���Ϊ�ϲ����ͷ���
    {
        pMergeHead = pHead1;
        pMergeHead->pNext = Merge_Recursively(pHead1->pNext,pHead2); //��ʣ�µ�Ԫ�ؽ��кϲ�
    }
    else if(pHead1->value > pHead2->value)
    {
        pMergeHead = pHead2;
        pMergeHead->pNext = Merge_Recursively(pHead1,pHead2->pNext);
    }
    return pMergeHead;
}
//�ϲ�������������--�ǵݹ�-�ܽ��������ͬԪ������
template<class T>
ListNode<T>* Merge_Iteratively(ListNode<T>* pHead1,ListNode<T>* pHead2)
{
    if(pHead1 == NULL)                //�������1Ϊ�գ����úϲ���ֱ�ӷ�������2
        return pHead2;
    if(pHead2 == NULL)                //�������2Ϊ�գ����úϲ���ֱ�ӷ�������1
        return pHead1;

    ListNode<T>* pMergeHead = NULL;       //����һ���ϲ�֮���ͷ��㣬�����������С��ͷ���
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
    ListNode<T>* pNode = pMergeHead;       //����һ���ڵ�����¼�ϲ������������һ��Ԫ��
    while(pHead1 && pHead2)
    {
        if(pHead1->value <= pHead2->value) //�������1��ͷ���Ƚ�С����������1��ͷ���Ϊ�ϲ����ͷ���
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
    if(pHead1 == NULL)                    //����һ������Ϊ�գ���ֱ��������һ��
        pNode->pNext = pHead2;
    else if(pHead2 == NULL)
        pNode->pNext = pHead1;
    return pMergeHead;                    //���غϲ�֮���ͷ���
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
