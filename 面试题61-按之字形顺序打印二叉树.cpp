/*************************************/
//按之字形顺序打印二叉树
/*************************************/
#include <iostream>
#include <stack>
#include "BinaryTree.h"

using namespace std;
template<class T>
void Print(BinaryTreeNode<T>* pRoot)
{
    if(pRoot == NULL)
        return;

    stack <BinaryTreeNode<T>* > levels[2];  //定义两个栈
    int current = 0;
    int next = 1;

    levels[current].push(pRoot);          //将当前的根节点压入栈
    while(!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode<T>* pNode = levels[current].top();  //取栈顶元素
        levels[current].pop();                             //弹出栈顶元素

        cout << pNode->value << ' ';

        if(current == 0)
        {
            if(pNode->pLeft != NULL)            //从左往右压入，从右往左出
                levels[next].push(pNode->pLeft);
            if(pNode->pRight != NULL)
                levels[next].push(pNode->pRight);
        }
        else                                    //从右往左压入，从左往右出
        {
            if(pNode->pRight != NULL)
                levels[next].push(pNode->pRight);
            if(pNode->pLeft != NULL)
                levels[next].push(pNode->pLeft);
        }

        if(levels[current].empty())  //如果当前层打印完，则交换两个栈
        {
            cout << endl;
            current = 1 - current;   //交换栈
            next = 1 - next;
        }
    }
}
int main(void)
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* pNode1 = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* pNode2 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* pNode3 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* pNode4 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* pNode5 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* pNode6 = new BinaryTreeNode<int>(6);

    ConnectTreeNodes(root, pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3, pNode4);
    ConnectTreeNodes(pNode2, pNode5, pNode6);

    Print(root);
    return 0;
}







