//����������Ľڵ�
#include<iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
    T value;                //Ԫ��ֵ
    BinaryTreeNode* pLeft;   //��ڵ�
    BinaryTreeNode* pRight;  //�ҽڵ�
    BinaryTreeNode(){pLeft = pRight = NULL;}       //Ĭ�Ϲ��캯��
    BinaryTreeNode(const T& the_value):value(the_value)  //���캯��
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
