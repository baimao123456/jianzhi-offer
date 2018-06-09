//定义链表的节点
#ifndef ListNode_
#define ListNode_
//定义链表节点
template<class T>
struct ListNode
{
    T value;
    ListNode* pNext;
    ListNode(int value):value(value){ pNext = NULL;} //构造函数
};
#endif // ListNOde_
