#include <iostream>
using namespace std;
//定义复杂链表的节点
struct ComplexListNode
{
    int m_nValue;                  //元素值
    ComplexListNode* m_pNext;     //下一个节点
    ComplexListNode* m_pSibling;  //任意一个节点
    //构造函数
    ComplexListNode(int value_node = 0):m_nValue(value_node)
    {
        m_pNext = NULL;
        m_pSibling = NULL;
    }
    //复制构造函数
    ComplexListNode(ComplexListNode* p)
    {
        m_nValue = p->m_nValue;
        m_pNext = p->m_pNext;
        m_pSibling = p->m_pSibling;
    }
};
//连接节点
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != NULL)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}
//打印链表节点
void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);

        if(pNode->m_pSibling != NULL)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->m_pNext;
    }
}
//克隆每个节点
void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    /*while(pNode != NULL)              //复制每个节点，并放到所要复制节点的后边
    {   //原来的方法
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;

        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }*/
    while(pNode != NULL)                //复制每个节点，并放到所要复制节点的后边
    {
        //改进的方法
        ComplexListNode* pCloned = new ComplexListNode(pNode);  //利用复制构造函数来复制节点
        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }
}
//连接每个节点的 m_pSibling
void ConnectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)              //遍历寻找节点的m_pSibling，并进行连接
    {
        ComplexListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != NULL)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;  //注意这里还得取m_pNext，否则找到的是原来的节点
        }
        pNode = pCloned->m_pNext;    //指向原来的下一个节点（不是复制后的节点）
    }
}
//连接复制的节点
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = NULL;  //用来指向复制链表的头结点
    ComplexListNode* pClonedNode = NULL;  //用来指向复制节点

    if(pNode != NULL)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;  //定义复制链表的头结点
        //pNode->m_pNext = pClonedNode->m_pNext;     //指向下一个复制节点
        //pNode = pNode->m_pNext;
        pNode = pNode->m_pNext->m_pNext;
    }

    while(pNode != NULL)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        //pNode->m_pNext = pClonedNode->m_pNext;
        //pNode = pNode->m_pNext;
        pNode = pNode->m_pNext->m_pNext;        //中间隔过复制节点
    }
    return pClonedHead;
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    cout << "CloneNodes is done!!" << endl;
    ConnectSiblingNodes(pHead);
    cout << "ConnectSiblingNodes is done!!" << endl;
    return ReconnectNodes(pHead);
}
int main()
{
    cout << "hello world" << endl;
    //定义节点
    ComplexListNode* pNode1 = new ComplexListNode(1);
    ComplexListNode* pNode2 = new ComplexListNode(2);
    ComplexListNode* pNode3 = new ComplexListNode(3);
    ComplexListNode* pNode4 = new ComplexListNode(4);
    ComplexListNode* pNode5 = new ComplexListNode(5);
    //连接节点
    /*BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);*/

    BuildNodes(pNode1, pNode2, NULL);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    PrintList(pNode1);

    ComplexListNode* root = Clone(pNode1);
    cout << "after clone, the list is : " << endl;
    PrintList(root);


    cout << "my test !!!" << endl;
    ComplexListNode* mynode = new ComplexListNode(13);
    cout << "before value" <<mynode->m_nValue << endl;
    ComplexListNode* mynodecopy = new ComplexListNode(mynode);
    cout << "after value" <<mynodecopy->m_nValue << endl;
    return 0;
}
