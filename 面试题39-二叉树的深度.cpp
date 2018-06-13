/********************************/
//�����������
/********************************/
#include <iostream>
#include <algorithm>
#include "BinaryTree.h"

using namespace std;
//�����������
int TreeDepth(BinaryTreeNode<int>* pRoot)
{
    if(pRoot == NULL)
        return 0;

    int nLeft = TreeDepth(pRoot->pLeft);                 //���������������
    int nRight = TreeDepth(pRoot->pRight);               //���������������

    return max(nLeft, nRight) + 1;//������Ƚϴ������
}
//�ж��Ƿ���ƽ��������Ҫ�����ڵ���
bool isBalenced(BinaryTreeNode<int>* pRoot)
{
    if(pRoot == NULL)
        return true;

    int nLeft = TreeDepth(pRoot->pLeft);                 //���������������
    int nRight = TreeDepth(pRoot->pRight);               //���������������
    int diff = nLeft - nRight;                           //������������Ȳ�ֵ
    if(abs(diff) > 1)                                    //���������1������ƽ����
        return false;

    return isBalenced(pRoot->pLeft) && isBalenced(pRoot->pRight); //��������������ƽ�������������pRootΪ���ڵ��������ƽ�������
}
//�ж��Ƿ���ƽ����������Ҫ�������һ�νڵ㣬һ�߱���һ���ж��Ƿ�ƽ��
bool isBalenced(BinaryTreeNode<int>* pRoot, int& pDepth)
{
    if(pRoot == NULL)
    {
        pDepth = 0;
        return true;
    }

    int nLeft, nRight;
    if (isBalenced(pRoot->pLeft, nLeft)         //�������������ƽ�⣬�����жϸ��ڵ��Ƿ�ƽ�⣬���򷵻�false
        && isBalenced(pRoot->pRight, nRight))
    {
        int diff = nLeft - nRight;               //������������Ȳ�ֵ
        if(abs(diff) <= 1)                       //������<=1������ƽ����,�ҷ����������
        {
            pDepth = max(nLeft, nRight) + 1;  //��prootΪ���ڵ���������
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
