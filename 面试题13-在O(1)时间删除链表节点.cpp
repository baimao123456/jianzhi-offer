/*************************************/
//在O(1)时间内产出节点
/*************************************/
#include<iostream>
using namespace std;
//定义链表节点
struct ListNode
{
    int value;
    ListNode* next;
    ListNode(int value):value(value){} //构造函数，给value赋初值
};
void DeleteNode(ListNode** pHead,ListNode* pToDeleted)
{
    if(pHead == NULL || pToDeleted == NULL) //如果头结点或者删除的节点为空，则返回
        return;
    if(pToDeleted->next != NULL)            //如果要删除的节点不是尾节点
    {
        ListNode* pNext = pToDeleted->next;   //获得要删除节点的下一个节点
        pToDeleted->value = pNext->value;     //将pNext的节点值赋值给要删除的节点，
        pToDeleted->next = pNext->next;       //重新连接链表

        delete pNext;                         //删除节点
        pNext = NULL;
    }
    else if(*pHead == pToDeleted)             //链表只有一个节点，则删除头结点（尾节点）
    {
        delete pToDeleted;
        pToDeleted = NULL;
        pHead = NULL;
    }
    else                                      //多个节点，且要删除的是尾节点,则需要遍历节点找到尾节点的前一个节点，来删除
    {
        ListNode* Node = *pHead;
        while(Node->next != NULL)             //找到尾节点的前一个节点
        {
            Node = Node->next;
        }
        Node->next = NULL;                    //此时Node是尾节点，所以Node->next = NULL
        delete pToDeleted;                    //删除节点
        pToDeleted = NULL;
    }
}
int main()
{
    ListNode* p = new ListNode(0);
    return 0;
}
