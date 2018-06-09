//定义二叉树的节点
#include<iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
    T value;                //元素值
    BinaryTreeNode* pLeft;   //左节点
    BinaryTreeNode* pRight;  //右节点
    BinaryTreeNode(){pLeft = pRight = NULL;}       //默认构造函数
    BinaryTreeNode(const T& the_value):value(the_value)  //构造函数
    {
        pLeft = pRight = NULL;
    }
    BinaryTreeNode(const T& the_value,
                   BinaryTreeNode<T>* LeftNode,
                   BinaryTreeNode<T>* RightNode):value(the_value)
    {
        pLeft = LeftNode;
        pRight = RightNode;
    }
};
