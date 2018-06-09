/*********************************/
//从上到下打印二叉树
/*********************************/
#include<iostream>
#include<queue>
#include "BinaryTree.h"
using namespace std;
//层级遍历
template<class T>
void PrintFromTopToBottom(BinaryTreeNode<T>* root)
{
    if(!root) return;                 //如果树为空，直接返回
    deque<BinaryTreeNode<T>* >dequeTreeNode; //定义一个双向队列，用来存放树节点，

    dequeTreeNode.push_back(root);           //将根节点压入到队尾中去，
    while(dequeTreeNode.size())
    {
        BinaryTreeNode<T>* pNode = dequeTreeNode.front();  //取出队列的首元素，然后打印出来
        dequeTreeNode.pop_front();

        cout << pNode->value << ',';         //打印节点值

        if(pNode->pLeft)                     //如果PNode的左右子树不为空，则压入队列中去
            dequeTreeNode.push_back(pNode->pLeft);

        if(pNode->pRight)
            dequeTreeNode.push_back(pNode->pRight);
    }
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
    cout << endl << "after tree's level order print is : " << endl;
    PrintFromTopToBottom(root);
    return 0;
}
