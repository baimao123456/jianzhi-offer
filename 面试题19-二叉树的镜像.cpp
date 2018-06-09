/*******************************/
//二叉树的镜像
/******************************/
#include<iostream>
#include "BinaryTree.h"
using namespace std;

template<class T>
void MirrorRecursively(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    if(pNode->pLeft == NULL && pNode->pRight == NULL) //单节点,镜像就是自己
        return;

    BinaryTreeNode<T>* pTemp = pNode->pLeft;          //临时存储左树
    pNode->pLeft = pNode->pRight;                     //左右树交换位置
    pNode->pRight = pTemp;

    if(pNode->pLeft)                                  //如果pNode的左树不为空，继续交换左右节点
        MirrorRecursively(pNode->pLeft);

    if(pNode->pRight)                                  //如果pNode的右树不为空，继续交换左右节点
        MirrorRecursively(pNode->pRight);
}

int main()
{
    cout << "binarytree mirror test" <<endl;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* pNode6 = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int>* pNode10 = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* pNode5 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* pNode7 = new BinaryTreeNode<int>(7);
    BinaryTreeNode<int>* pNode9 = new BinaryTreeNode<int>(9);
    BinaryTreeNode<int>* pNode11 = new BinaryTreeNode<int>(11);

    ConnectTreeNodes(root, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    cout << "befor mirror the tree's preorder print is : " << endl;
    Preorder_print(root);
    cout << endl;
    MirrorRecursively(root);
    cout << "after mirror the tree's preorder print is : " << endl;
    Preorder_print(root);
    return 0;
}
