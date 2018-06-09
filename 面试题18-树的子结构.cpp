/*******************************/
//树的子结构
/*******************************/
#include<iostream>
#include"BinaryTree.h"
using namespace std;
//判断以proot1和proot2为根节点的树是否有相同结构
template<class T>
bool DoesTree1HaveTree2(BinaryTreeNode<T>* proot1,BinaryTreeNode<T>* proot2)
{
    if(proot2 == NULL)   //如果prrot2先为NULL,则返回true,因为proot2是子树，所以节点应该比proot1少
        return true;
    if(proot1 == NULL)
        return false;
    if(proot1->value != proot2->value)    //如果有的节点不相同，则返回false
        return false;

    return DoesTree1HaveTree2(proot1->pLeft,proot2->pLeft)&&   //如果子树的每个节点均相同
            DoesTree1HaveTree2(proot1->pRight,proot2->pRight);
}
//判断以proot2为根节点的树是否是以proot1为根节点的树的子结构
template<class T>
bool HasSubTree(BinaryTreeNode<T>* proot1,BinaryTreeNode<T>* proot2)
{
    bool result = false;                   //标志位，true为有子树，false则是没有
    if(proot1 != NULL && proot2 != NULL)
    {
        if(proot1->value == proot2->value) //如果两个节点相同，进一步判断
            result = DoesTree1HaveTree2(proot1,proot2);
        if(!result)
            result = HasSubTree(proot1->pLeft,proot2);   //继续在root1的左子树寻找和proot2相同的节点
        if(!result)
            result = HasSubTree(proot1->pRight,proot2);  //继续在root1的右子树寻找和proot2相同的节点
    }
    return result;
}
int main()
{
    cout << "树的子结构测试" <<endl;
    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* pNode8 = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* pNode7 = new BinaryTreeNode<int>(7);
    BinaryTreeNode<int>* pNode9 = new BinaryTreeNode<int>(9);
    BinaryTreeNode<int>* pNode2 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* pNode4 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* pNode77 = new BinaryTreeNode<int>(7);

    ConnectTreeNodes(root1, pNode8, pNode7);
    ConnectTreeNodes(pNode8, pNode9, pNode2);
    ConnectTreeNodes(pNode2, pNode4, pNode7);

    BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(8);
    BinaryTreeNode<int>* pNode99 = new BinaryTreeNode<int>(9);
    BinaryTreeNode<int>* pNode22 = new BinaryTreeNode<int>(2);
    ConnectTreeNodes(root2, pNode99, pNode22);

    Preorder_print(root1);     //前序遍历打印
    cout << endl;
    Preorder_print(root2);
    cout << endl << "tree1 has tree2 ?  ";
    cout << HasSubTree(root1,root2);
    return 0;
}
