/*************************************/
//�ԳƵĶ�����
/*************************************/
#include <iostream>
#include "BinaryTree.h"
using namespace std;
template <class T>
bool isSymmetrical(BinaryTreeNode<T>* pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}
template <class T>
bool isSymmetrical(BinaryTreeNode<T>* pNode1, BinaryTreeNode<T>* pNode2)
{
    if(pNode1 == NULL && pNode2 == NULL)  //��������ڵ㶼Ϊ�գ��ǶԳ�
        return true;

    if(pNode1 == NULL || pNode2 == NULL)  //���ֻ��һ���ڵ�Ϊ�գ����ǶԳ�
        return false;

    if(pNode1->value != pNode2->value)    //��������ڵ㲻�ǿգ�����ֵ��ͬ��Ҳ���ǶԳƵ�
        return false;

    //��� ������� �� ���Һ��� ����ͬ�����ǶԳƵ�
    return isSymmetrical(pNode1->pLeft, pNode2->pRight)   //��һ�����������������
        && isSymmetrical(pNode1->pRight, pNode2->pLeft);  //��һ�������������Һ���
}
int main(void)
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* pNode1 = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int>* pNode2 = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int>* pNode3 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* pNode4 = new BinaryTreeNode<int>(7);
    BinaryTreeNode<int>* pNode5 = new BinaryTreeNode<int>(7);
    BinaryTreeNode<int>* pNode6 = new BinaryTreeNode<int>(5);

    ConnectTreeNodes(root, pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3, pNode4);
    ConnectTreeNodes(pNode2, pNode5, pNode6);

    Preorder_print(root);
    cout << endl << "the tree is symmetrical ? " << isSymmetrical(root);
    return 0;
}





