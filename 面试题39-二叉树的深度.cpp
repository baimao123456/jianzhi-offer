/********************************/
//二叉树的深度
/********************************/
#include <iostream>
#include <algorithm>
#include "BinaryTree.h"

using namespace std;
//计算树的深度
int TreeDepth(BinaryTreeNode<int>* pRoot)
{
    if(pRoot == NULL)
        return 0;

    int nLeft = TreeDepth(pRoot->pLeft);                 //计算左子树的深度
    int nRight = TreeDepth(pRoot->pRight);               //计算右子树的深度

    return max(nLeft, nRight) + 1;//返回深度较大的子树
}
//判断是否是平衡树，需要遍历节点多次
bool isBalenced(BinaryTreeNode<int>* pRoot)
{
    if(pRoot == NULL)
        return true;

    int nLeft = TreeDepth(pRoot->pLeft);                 //计算左子树的深度
    int nRight = TreeDepth(pRoot->pRight);               //计算右子树的深度
    int diff = nLeft - nRight;                           //左右子树的深度差值
    if(abs(diff) > 1)                                    //如果相差大于1，则不是平衡树
        return false;

    return isBalenced(pRoot->pLeft) && isBalenced(pRoot->pRight); //若左右子树均是平衡二叉树，则以pRoot为根节点的树才是平衡二叉树
}
//判断是否是平衡树，仅需要后序遍历一次节点，一边遍历一边判断是否平衡
bool isBalenced(BinaryTreeNode<int>* pRoot, int& pDepth)
{
    if(pRoot == NULL)
    {
        pDepth = 0;
        return true;
    }

    int nLeft, nRight;
    if (isBalenced(pRoot->pLeft, nLeft)         //如果左右子树均平衡，进而判断根节点是否平衡，否则返回false
        && isBalenced(pRoot->pRight, nRight))
    {
        int diff = nLeft - nRight;               //左右子树的深度差值
        if(abs(diff) <= 1)                       //如果相差<=1，则是平衡树,且返回树的深度
        {
            pDepth = max(nLeft, nRight) + 1;  //以proot为根节点的树的深度
            return true;
        }
    }
    return false;
}
bool isBalenced2(BinaryTreeNode<int>* pRoot)
{
    int depth = 0;
    return isBalenced(pRoot, depth);
}
int main(void)
{
    cout << "hello world" << endl;
    BinaryTreeNode<int>* pNULL = NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* pNode2 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* pNode3 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* pNode4 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* pNode5 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* pNode6 = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int>* pNode7 = new BinaryTreeNode<int>(7);

    ConnectTreeNodes(root, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, pNULL, pNode6);
    ConnectTreeNodes(pNode5, pNode7, pNULL);

    Preorder_print(root);

    cout << endl << "the depth of tree is : " << TreeDepth(root);
    cout << endl << "the tree is balenced ?  : " << isBalenced(root);
    cout << endl << "the tree is balenced ?  : " << isBalenced2(root);
    return 0;
}
