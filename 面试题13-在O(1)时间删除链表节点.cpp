/*************************************/
//��O(1)ʱ���ڲ����ڵ�
/*************************************/
#include<iostream>
using namespace std;
//��������ڵ�
struct ListNode
{
    int value;
    ListNode* next;
    ListNode(int value):value(value){} //���캯������value����ֵ
};
void DeleteNode(ListNode** pHead,ListNode* pToDeleted)
{
    if(pHead == NULL || pToDeleted == NULL) //���ͷ������ɾ���Ľڵ�Ϊ�գ��򷵻�
        return;
    if(pToDeleted->next != NULL)            //���Ҫɾ���Ľڵ㲻��β�ڵ�
    {
        ListNode* pNext = pToDeleted->next;   //���Ҫɾ���ڵ����һ���ڵ�
        pToDeleted->value = pNext->value;     //��pNext�Ľڵ�ֵ��ֵ��Ҫɾ���Ľڵ㣬
        pToDeleted->next = pNext->next;       //������������

        delete pNext;                         //ɾ���ڵ�
        pNext = NULL;
    }
    else if(*pHead == pToDeleted)             //����ֻ��һ���ڵ㣬��ɾ��ͷ��㣨β�ڵ㣩
    {
        delete pToDeleted;
        pToDeleted = NULL;
        pHead = NULL;
    }
    else                                      //����ڵ㣬��Ҫɾ������β�ڵ�,����Ҫ�����ڵ��ҵ�β�ڵ��ǰһ���ڵ㣬��ɾ��
    {
        ListNode* Node = *pHead;
        while(Node->next != NULL)             //�ҵ�β�ڵ��ǰһ���ڵ�
        {
            Node = Node->next;
        }
        Node->next = NULL;                    //��ʱNode��β�ڵ㣬����Node->next = NULL
        delete pToDeleted;                    //ɾ���ڵ�
        pToDeleted = NULL;
    }
}
int main()
{
    ListNode* p = new ListNode(0);
    return 0;
}
