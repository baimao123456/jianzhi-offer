#include <iostream>
using namespace std;
//���帴������Ľڵ�
struct ComplexListNode
{
    int m_nValue;                  //Ԫ��ֵ
    ComplexListNode* m_pNext;     //��һ���ڵ�
    ComplexListNode* m_pSibling;  //����һ���ڵ�
    //���캯��
    ComplexListNode(int value_node = 0):m_nValue(value_node)
    {
        m_pNext = NULL;
        m_pSibling = NULL;
    }
    //���ƹ��캯��
    ComplexListNode(ComplexListNode* p)
    {
        m_nValue = p->m_nValue;
        m_pNext = p->m_pNext;
        m_pSibling = p->m_pSibling;
    }
};
//���ӽڵ�
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != NULL)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}
//��ӡ����ڵ�
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
//��¡ÿ���ڵ�
void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    /*while(pNode != NULL)              //����ÿ���ڵ㣬���ŵ���Ҫ���ƽڵ�ĺ��
    {   //ԭ���ķ���
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;

        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }*/
    while(pNode != NULL)                //����ÿ���ڵ㣬���ŵ���Ҫ���ƽڵ�ĺ��
    {
        //�Ľ��ķ���
        ComplexListNode* pCloned = new ComplexListNode(pNode);  //���ø��ƹ��캯�������ƽڵ�
        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }
}
//����ÿ���ڵ�� m_pSibling
void ConnectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)              //����Ѱ�ҽڵ��m_pSibling������������
    {
        ComplexListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != NULL)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;  //ע�����ﻹ��ȡm_pNext�������ҵ�����ԭ���Ľڵ�
        }
        pNode = pCloned->m_pNext;    //ָ��ԭ������һ���ڵ㣨���Ǹ��ƺ�Ľڵ㣩
    }
}
//���Ӹ��ƵĽڵ�
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = NULL;  //����ָ���������ͷ���
    ComplexListNode* pClonedNode = NULL;  //����ָ���ƽڵ�

    if(pNode != NULL)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;  //���帴�������ͷ���
        //pNode->m_pNext = pClonedNode->m_pNext;     //ָ����һ�����ƽڵ�
        //pNode = pNode->m_pNext;
        pNode = pNode->m_pNext->m_pNext;
    }

    while(pNode != NULL)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        //pNode->m_pNext = pClonedNode->m_pNext;
        //pNode = pNode->m_pNext;
        pNode = pNode->m_pNext->m_pNext;        //�м�������ƽڵ�
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
    //����ڵ�
    ComplexListNode* pNode1 = new ComplexListNode(1);
    ComplexListNode* pNode2 = new ComplexListNode(2);
    ComplexListNode* pNode3 = new ComplexListNode(3);
    ComplexListNode* pNode4 = new ComplexListNode(4);
    ComplexListNode* pNode5 = new ComplexListNode(5);
    //���ӽڵ�
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
