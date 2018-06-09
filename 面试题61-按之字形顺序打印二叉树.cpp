/*************************************/
//��֮����˳���ӡ������
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

    stack <BinaryTreeNode<T>* > levels[2];  //��������ջ
    int current = 0;
    int next = 1;

    levels[current].push(pRoot);          //����ǰ�ĸ��ڵ�ѹ��ջ
    while(!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode<T>* pNode = levels[current].top();  //ȡջ��Ԫ��
        levels[current].pop();                             //����ջ��Ԫ��

        cout << pNode->value << ' ';

        if(current == 0)
        {
            if(pNode->pLeft != NULL)            //��������ѹ�룬���������
                levels[next].push(pNode->pLeft);
            if(pNode->pRight != NULL)
                levels[next].push(pNode->pRight);
        }
        else                                    //��������ѹ�룬�������ҳ�
        {
            if(pNode->pRight != NULL)
                levels[next].push(pNode->pRight);
            if(pNode->pLeft != NULL)
                levels[next].push(pNode->pLeft);
        }

        if(levels[current].empty())  //�����ǰ���ӡ�꣬�򽻻�����ջ
        {
            cout << endl;
            current = 1 - current;   //����ջ
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







