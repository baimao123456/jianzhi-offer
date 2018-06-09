/*************************************/
//二叉树的下一个节点
/*************************************/
#include <iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
    T value;                  //元素值
    BinaryTreeNode* pLeft;    //左节点
    BinaryTreeNode* pRight;   //右节点
    BinaryTreeNode* pParent;  //父节点

    BinaryTreeNode(){pLeft = pRight = pParent = NULL;}       //默认构造函数
    BinaryTreeNode(const T& the_value):value(the_value)  //构造函数
    {
        pLeft = pRight = pParent = NULL;
    }
};
template<class T>
void ConnectTreeNodes(BinaryTreeNode<T>* pParent,
                      BinaryTreeNode<T>* pLeft,
                      BinaryTreeNode<T>* pRight)
{
    if(pParent != NULL)
    {
        pParent->pLeft = pLeft;
        pParent->pRight = pRight;

        if(pLeft != NULL)
            pLeft->pParent = pParent;
        if(pRight != NULL)
            pRight->pParent = pParent;
    }
}
//中序遍历
template<class T>
void Inorder_print(BinaryTreeNode<T>* pRoot)
{
    if(pRoot == NULL)
        return;

    //BinaryTreeNode<T>* pNode = pRoot;
    Inorder_print(pRoot->pLeft);
    cout << pRoot->value << ',';
    Inorder_print(pRoot->pRight);
}
//获得中序遍历的下一个节点
template<class T>
BinaryTreeNode<T>* GetNext(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return NULL;

    BinaryTreeNode<T>* pNext = NULL;
    if(pNode->pRight != NULL)       //如果节点存在右子树，则下一个节点就是右子树的最左节点
    {
        BinaryTreeNode<T>* pRight = pNode->pRight; //右子树根节点
        while(pRight->pLeft != NULL)
            pRight = pRight->pLeft;
        pNext = pRight;             //最左节点
    }
    else if(pNode->pParent != NULL) //如果当前节点没有右子树，且存在父节点
    {
        BinaryTreeNode<T>* pCurrent = pNode;
        BinaryTreeNode<T>* pParent = pNode->pParent;

        //找到一个节点，当前节点存在这个节点的左子树
        while(pParent != NULL && pCurrent == pParent->pRight)
        {
            pCurrent = pParent;
            pParent = pParent->pParent;
        }
        pNext = pParent;              //如果while条件不满足，下一节点就是当前节点的父节点
    }
}
int main(void)
{
    BinaryTreeNode<char>* pNodea = new BinaryTreeNode<char>('a');
    BinaryTreeNode<char>* pNodeb = new BinaryTreeNode<char>('b');
    BinaryTreeNode<char>* pNodec = new BinaryTreeNode<char>('c');
    BinaryTreeNode<char>* pNoded = new BinaryTreeNode<char>('d');
    BinaryTreeNode<char>* pNodee = new BinaryTreeNode<char>('e');
    BinaryTreeNode<char>* pNodef = new BinaryTreeNode<char>('f');
    BinaryTreeNode<char>* pNodeg = new BinaryTreeNode<char>('g');
    BinaryTreeNode<char>* pNodeh = new BinaryTreeNode<char>('h');
    BinaryTreeNode<char>* pNodei = new BinaryTreeNode<char>('i');

    ConnectTreeNodes(pNodea, pNodeb, pNodec);
    ConnectTreeNodes(pNodeb, pNoded, pNodee);
    ConnectTreeNodes(pNodec, pNodef, pNodeg);
    ConnectTreeNodes(pNodee, pNodeh, pNodei);

    Inorder_print(pNodea);
    BinaryTreeNode<char>* pNext = GetNext(pNodee);
    if(pNext != NULL)
        cout << endl << pNext->value;
    else
        cout << endl << "the current node is last!!" << endl;
    return 0;
}





