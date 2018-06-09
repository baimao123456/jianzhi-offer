/*******************************/
//二叉树搜索树和双向链表
/******************************/
#include<iostream>
#include "BinaryTree.h"
using namespace std;
//改变节点的左右节点的指针方向
//pNode为树的根节点，pLastNodeList指向的是已经完成转换的链表的最后一个节点（最后一个元素）
void ConvertNode(BinaryTreeNode<int>* pNode, BinaryTreeNode<int>** pLastNodeList)
{
    if(pNode == NULL)                                 //若节点为空，直接返回
        return;

    BinaryTreeNode<int>* pCurrent = pNode;                 //定义一个遍历树的临时节点

    if(pCurrent->pLeft != NULL)                 //若左子树不为空，则进行递归改变节点指针方向
        ConvertNode(pCurrent->pLeft, pLastNodeList);  //执行完成后，pLastNodeList指向的是左子树的最大的元素，pCurrent是pNode

    pCurrent->pLeft = *pLastNodeList;                 //根节点指向左子树中最大的元素

    if((*pLastNodeList) != NULL)
        (*pLastNodeList)->pRight = pCurrent;          //如果左子树中最大的元素非空，则其右指针指向根节点

    *pLastNodeList = pCurrent;                        //此时双向链表中的尾节点就是 *pLastNodeList

    if(pCurrent->pRight != NULL)                //若右子树不为空，则进行递归改变节点指针方向
        ConvertNode(pCurrent->pRight, pLastNodeList); //执行完成后，pLastNodeList指向的是右子树的最大的元素，pCurrent指向的是根节点
}
//二叉搜索树-->链表 的转换
BinaryTreeNode<int>* Convert(BinaryTreeNode<int>* pRootOfTree)
{
    BinaryTreeNode<int>* pLastNodeList = NULL;
    ConvertNode(pRootOfTree, &pLastNodeList);          //进行转换

    //遍历链表找到头结点
    BinaryTreeNode<int>* pHeadOfList = pLastNodeList;
    while(pHeadOfList != NULL && pHeadOfList->pLeft != NULL)
        pHeadOfList = pHeadOfList->pLeft;

    return pHeadOfList;                               //返回找到的头结点
}
int main()
{
    cout << "binarytree mirror test" <<endl;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* pNode6 = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int>* pNode14 = new BinaryTreeNode<int>(14);
    BinaryTreeNode<int>* pNode4 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* pNode8 = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* pNode12 = new BinaryTreeNode<int>(12);
    BinaryTreeNode<int>* pNode16 = new BinaryTreeNode<int>(16);

    ConnectTreeNodes(root, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);
    cout << "befor mirror the tree's Inorder print is : " << endl;
    Inorder_print(root);

    BinaryTreeNode<int>* pHeadOfList = Convert(root);
    cout << endl << "the list of binarytree is : " << endl;

    while(pHeadOfList != NULL)
    {
        cout << pHeadOfList->value << ' ';
        pHeadOfList = pHeadOfList->pRight;
    }
    cout << endl;
    return 0;
}
