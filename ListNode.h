//��������Ľڵ�
#ifndef ListNode_
#define ListNode_
//��������ڵ�
template<class T>
struct ListNode
{
    T value;
    ListNode* pNext;
    ListNode(int value):value(value){ pNext = NULL;} //���캯��
};
#endif // ListNOde_
