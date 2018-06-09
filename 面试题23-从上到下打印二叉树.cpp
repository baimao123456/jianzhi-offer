/*********************************/
//���ϵ��´�ӡ������
/*********************************/
#include<iostream>
#include<queue>
#include "BinaryTree.h"
using namespace std;
//�㼶����
template<class T>
void PrintFromTopToBottom(BinaryTreeNode<T>* root)
{
    if(!root) return;                 //�����Ϊ�գ�ֱ�ӷ���
    deque<BinaryTreeNode<T>* >dequeTreeNode; //����һ��˫����У�����������ڵ㣬

    dequeTreeNode.push_back(root);           //�����ڵ�ѹ�뵽��β��ȥ��
    while(dequeTreeNode.size())
    {
        BinaryTreeNode<T>* pNode = dequeTreeNode.front();  //ȡ�����е���Ԫ�أ�Ȼ���ӡ����
        dequeTreeNode.pop_front();

        cout << pNode->value << ',';         //��ӡ�ڵ�ֵ

        if(pNode->pLeft)                     //���PNode������������Ϊ�գ���ѹ�������ȥ
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
