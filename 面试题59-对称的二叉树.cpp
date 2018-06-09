/*************************************/
//对称的二叉树
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
    if(pNode1 == NULL && pNode2 == NULL)  //如果两个节点都为空，是对称
        return true;

    if(pNode1 == NULL || pNode2 == NULL)  //如果只有一个节点为空，不是对称
        return false;

    if(pNode1->value != pNode2->value)    //如果两个节点不是空，但是值不同，也不是对称的
        return false;

    //如果 先左后右 和 先右后左 均相同，则是对称的
    return isSymmetrical(pNode1->pLeft, pNode2->pRight)   //第一个参数控制先左后右
        && isSymmetrical(pNode1->pRight, pNode2->pLeft);  //第一个参数控制先右后左
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





