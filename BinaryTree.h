#ifndef BinaryTree_
#define BinaryTree_
#include<iostream>
using namespace std;
#include"BinaryTreeNode.h"
//���Ӹ��ڵ���ӽڵ�
template<class T>
void ConnectTreeNodes(BinaryTreeNode<T>* pParent,
                      BinaryTreeNode<T>* pLeft,
                      BinaryTreeNode<T>* pRight)
{
    if(pParent != NULL)
    {
        pParent->pLeft = pLeft;
        pParent->pRight = pRight;
    }
}
//ǰ�����
template<class T>
void Preorder_print(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    cout << pNode->value << ',';
    Preorder_print(pNode->pLeft);
    Preorder_print(pNode->pRight);
}
//�������
template<class T>
void Inorder_print(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    Inorder_print(pNode->pLeft);
    cout << pNode->value << ',';
    Inorder_print(pNode->pRight);
}
//�������
template<class T>
void Postorder_print(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    Postorder_print(pNode->pLeft);
    Postorder_print(pNode->pRight);
    cout << pNode->value << ',';
}
#endif // BinaryTree_
