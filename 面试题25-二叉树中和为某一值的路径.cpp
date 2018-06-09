/************************/
//��������  ��Ϊĳһֵ  ��·��
/************************/
#include<iostream>
#include"BinaryTree.h"
#include<vector>
using namespace std;
//���õݹ齫�ڵ������ͣ�ͨ���жϽڵ�ĺ���ȷ���ǲ��Ƿ���������·��
template<class T>
void FindPath(BinaryTreeNode<T>* pRoot,int expectedSum,vector<T>& path,int currentSum)
{
    currentSum += pRoot->value;      //���ڵ�ֵ���
    path.push_back(pRoot->value);    //����ǰ�ڵ���ӵ�·����

    //�����Ҷ�ڵ㣬����·���ϵĺ͵��������ֵ�����ӡ����·��
    bool isLeaf = pRoot->pLeft == NULL && pRoot->pRight == NULL;
    if(currentSum == expectedSum && isLeaf)
    {
        cout << endl << "A path is found" << endl;
        vector<int>::iterator it = path.begin();
        for(;it != path.end();++it)   //��ӡ·��
            cout << *it << ' ';
        cout << endl;
    }

    //�������Ҷ�ڵ㣬����������ӽڵ�
    if(pRoot->pLeft != NULL)
        FindPath(pRoot->pLeft,expectedSum,path,currentSum);

    if(pRoot->pRight != NULL)
        FindPath(pRoot->pRight,expectedSum,path,currentSum);
    //��ʱ��ǰ�ڵ���Ҷ�ڵ㣬���ǺͲ�������������ʱ�򷵻ظ��ڵ�
    //���ظ��ڵ�֮ǰ����·����ɾ����ǰ�ڵ�
    path.pop_back();
}
template<class T>
void FindPath(BinaryTreeNode<T>* pRoot,int expectedSum)
{
    if(pRoot == NULL)         //�����Ϊ�գ�ֱ�ӷ���
        return;

    vector<T> path;           //�������·��
    int currentSum = 0;       //��ǰ�ĺ�
    FindPath(pRoot,expectedSum,path,currentSum);
}
/*******************************/
//DFS(�����������) ����·������ÿ����һ���ڵ㣬����left��ȥ��ǰ�ڵ��ֵ��ֱ��left�ͽڵ��ֵ���
/*******************************/
vector<int>tree_path;              //�������·��
void DfsFindPath(BinaryTreeNode<int>* pNode,int left)
{
    tree_path.push_back(pNode->value);
    //����ҵ���һ��·�����ҵ�ǰ�ڵ㲻��Ҷ�ڵ㣬���ӡ
    if(left - pNode->value == 0 && !pNode->pLeft && !pNode->pRight)
    {
        cout << endl << "A path is found" << endl;
        vector<int>::iterator it = tree_path.begin();
        for(;it != tree_path.end();++it)      //��ӡ·��
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
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);    //����ڵ�
    BinaryTreeNode<int>* pNode5 = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int>* pNode12 = new BinaryTreeNode<int>(12);
    BinaryTreeNode<int>* pNode4 = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int>* pNode7 = new BinaryTreeNode<int>(7);

    ConnectTreeNodes(root,pNode5,pNode12);                      //���ӽڵ�
    ConnectTreeNodes(pNode5,pNode4,pNode7);

    Preorder_print(root);                                       //ǰ�������ӡ�ڵ�

    FindPath2(root,22);
    return 0;
}
