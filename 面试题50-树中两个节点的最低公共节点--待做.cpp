/*************************************/
//树中两个节点的最低公共子节点
//方法：查找两个节点的路径，判断公共子节点
/*************************************/
#include <iostream>
#include <list>
#include "BinaryTree.h"
using namespace std;
bool GetNodePath(BinaryTreeNode<int>* pRoot, BinaryTreeNode<int>* pNode,
                 list<BinaryTreeNode<int>*>& path)
{
    if(pRoot == NULL)
        return true;
    path.push_back(pRoot);
    bool found = false;

    vector<BinaryTreeNode<int> *>::iterator i = pRoot->
}
int main()
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(12);
    BinaryTreeNode<int>* pNode8 = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* pNode13 = new BinaryTreeNode<int>(13);
    BinaryTreeNode<int>* pNode6 = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int>* pNode10 = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* pNode5 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* pNode7 = new BinaryTreeNode<int>(7);
    BinaryTreeNode<int>* pNode9 = new BinaryTreeNode<int>(9);
    BinaryTreeNode<int>* pNode11 = new BinaryTreeNode<int>(11);
    ConnectTreeNodes(root, pNode8, pNode13);
    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Preorder_print(root);
    return 0;
}
