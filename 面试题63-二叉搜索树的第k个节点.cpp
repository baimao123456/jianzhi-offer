/*************************************/
//�����������ĵ�k���ڵ�
/*************************************/
#include <iostream>
#include <queue>
#include "BinaryTree.h"

using namespace std;
//�ҵ������������ĵ�k���ڵ�
//prootΪ���ĸ��ڵ㣬kΪ�ڵ���ţ�targetΪ�ҵ��ĵ�k���ڵ�
template<class T>
void KthNodeCore(BinaryTreeNode<T>* pRoot, unsigned int& k,
                               BinaryTreeNode<T>* &target)
{
    if(pRoot != NULL)
    {
        KthNodeCore(pRoot->pLeft, k, target);
        k--;                   //���kΪ0��˵����ǰ��pRoot���ǵ�k���ڵ�
        if(k == 0)
        {
            cout << pRoot->value << ',';
            target = pRoot;    //���ص�k���ڵ�
        }
        KthNodeCore(pRoot->pRight, k, target);
    }
}
template<class T>
BinaryTreeNode<T>* KthNode(BinaryTreeNode<T>* pRoot, unsigned int& k)
{
    if(pRoot == NULL || k <= 0)
        return NULL;
    BinaryTreeNode<T>* target = NULL;
    KthNodeCore(pRoot, k, target);
    return target;                //���ص�k���ڵ�
}
int main(void)
{
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

    Inorder_print(root);
    cout << endl;
    unsigned int k = 3;
    BinaryTreeNode<int>* KNode = KthNode(root,k);
    cout << endl << KNode->value;
    return 0;
}






