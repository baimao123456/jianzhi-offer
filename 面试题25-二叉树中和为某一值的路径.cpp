/************************/
//二叉树中  和为某一值  的路径
/************************/
#include<iostream>
#include"BinaryTree.h"
#include<vector>
using namespace std;
//利用递归将节点逐个求和，通过判断节点的和来确定是不是符合条件的路径
template<class T>
void FindPath(BinaryTreeNode<T>* pRoot,int expectedSum,vector<T>& path,int currentSum)
{
    currentSum += pRoot->value;      //将节点值相加
    path.push_back(pRoot->value);    //将当前节点添加到路径上

    //如果是叶节点，并且路径上的和等于输入的值，则打印这条路径
    bool isLeaf = pRoot->pLeft == NULL && pRoot->pRight == NULL;
    if(currentSum == expectedSum && isLeaf)
    {
        cout << endl << "A path is found" << endl;
        vector<int>::iterator it = path.begin();
        for(;it != path.end();++it)   //打印路径
            cout << *it << ' ';
        cout << endl;
    }

    //如果不是叶节点，则遍历它的子节点
    if(pRoot->pLeft != NULL)
        FindPath(pRoot->pLeft,expectedSum,path,currentSum);

    if(pRoot->pRight != NULL)
        FindPath(pRoot->pRight,expectedSum,path,currentSum);
    //此时当前节点是叶节点，但是和不满足条件，这时候返回父节点
    //返回父节点之前，在路径上删除当前节点
    path.pop_back();
}
template<class T>
void FindPath(BinaryTreeNode<T>* pRoot,int expectedSum)
{
    if(pRoot == NULL)         //如果树为空，直接返回
        return;

    vector<T> path;           //用来存放路径
    int currentSum = 0;       //当前的和
    FindPath(pRoot,expectedSum,path,currentSum);
}
/*******************************/
//DFS(深度优先搜索) 查找路径，，每到达一个节点，就用left减去当前节点的值，直到left和节点的值相等
/*******************************/
vector<int>tree_path;              //用来存放路径
void DfsFindPath(BinaryTreeNode<int>* pNode,int left)
{
    tree_path.push_back(pNode->value);
    //如果找到了一条路径，且当前节点不是叶节点，则打印
    if(left - pNode->value == 0 && !pNode->pLeft && !pNode->pRight)
    {
        cout << endl << "A path is found" << endl;
        vector<int>::iterator it = tree_path.begin();
        for(;it != tree_path.end();++it)      //打印路径
            cout << *it << ' ';
        cout << endl;
    }
    else
    {
        if(pNode->pLeft)
            DfsFindPath(pNode->pLeft,left - pNode->value);
        if(pNode->pRight)
            DfsFindPath(pNode->pRight,left - pNode->value);
    }
    tree_path.pop_back();

}
void FindPath2(BinaryTreeNode<int>* root,int expectedSum)
{
    if(root == NULL)
        return;
    DfsFindPath(root,expectedSum);
}
int main()
{
    cout << "binarytree path test" <<endl;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);    //定义节点
    BinaryTreeNode<int>* pNode5 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* pNode12 = new BinaryTreeNode<int>(12);
    BinaryTreeNode<int>* pNode4 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* pNode7 = new BinaryTreeNode<int>(7);

    ConnectTreeNodes(root,pNode5,pNode12);                      //连接节点
    ConnectTreeNodes(pNode5,pNode4,pNode7);

    Preorder_print(root);                                       //前序遍历打印节点

    FindPath2(root,22);
    return 0;
}
