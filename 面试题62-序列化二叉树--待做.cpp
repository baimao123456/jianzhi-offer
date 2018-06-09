/*************************************/
//ÐòÁÐ»¯¶þ²æÊ÷
/*************************************/
#include <iostream>
#include <stack>
#include "BinaryTree.h"

using namespace std;
template<class T>
void Serialize(BinaryTreeNode<T>* pRoot)
{
    if(pRoot == NULL)
    {
        cout << '$' << ',';
        return;
    }
    cout << pRoot->value << ',';
    Serialize(pRoot->pLeft);
    Serialize(pRoot->pRight);
}

template<class T>
BinaryTreeNode<T>* Des(char*& str)
{
    if(*str == '$')
    {
        ++(str);
        return NULL;
    }
    int num = 0;

    while(*str != '\0' && *str != ',')
        //num = num * 10 + atoi((str++));
        num = num*10 + (*(str++)-'0');
    ++(str);
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(num);
    if(*str == '\0')
        return root;
    else
        ++(str);

    root->pLeft = Des<T>(str);
    root->pRight = Des<T>(str);

    return root;
}
template<class T>
BinaryTreeNode<T>* Deserialize(char* str)
{
    if(str == NULL)
        return NULL;

    return Des<T>(str);
}
int main(void)
{
    BinaryTreeNode<int>* pNode1 = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* pNode2 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* pNode3 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* pNode4 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* pNode5 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* pNode6 = new BinaryTreeNode<int>(6);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, (BinaryTreeNode<int>* )NULL);
    ConnectTreeNodes(pNode3, pNode5, pNode6);

    Preorder_print(pNode1);
    cout << endl;
    Serialize(pNode1);
    cout << endl;
    BinaryTreeNode<int>* pRoot = Deserialize<int>("1,2,4,$,$,$,3,5,$,$,6,$,$");
    Preorder_print(pRoot);
    return 0;
}








