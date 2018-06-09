/*************************************/
//二叉树打印成多行
/*************************************/
#include <iostream>
#include <queue>
#include "BinaryTree.h"

using namespace std;
template<class T>
void Print(BinaryTreeNode<T>* pRoot)
{
    if(pRoot == NULL)
        return ;
    queue<BinaryTreeNode<T>* > nodes;
    nodes.push(pRoot);
    int nextLevel = 0;        //下一层需要打印的节点数
    int toBePrinted = 1;      //本层需要打印的节点数

    while(!nodes.empty())
    {
        BinaryTreeNode<T>* pNode = nodes.front();//取队首元素，并将他的左右子节点放进队列中
        cout << pNode->value << ' ';     //打印根节点的值

        if(pNode->pLeft != NULL)
        {
            nodes.push(pNode->pLeft);
            ++nextLevel;
        }
        if(pNode->pRight != NULL)
        {
            nodes.push(pNode->pRight);
            ++nextLevel;
        }

        nodes.pop();
        --toBePrinted;
        if(toBePrinted == 0)  //如果当前层的节点打印完，输出换行，继续打印下一层节点
        {
            cout << endl;
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
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

    Print(root);
    return 0;
}






