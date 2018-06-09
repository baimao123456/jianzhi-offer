/************************/
//二叉搜索树的后序遍历序列
/************************/
#include<iostream>
#include"BinaryTree.h"
#include<vector>
using namespace std;
//递归实现
template<class T>
bool VerifySequenceOfBST(T sequence[],int length)
{
    if(sequence == NULL || length <= 0)
        return false;
    T root = sequence[length - 1];       //根节点

    //在二叉搜索树中左子树的节点均小于根节点
    int i = 0;
    for(;i < length - 1;++i)
        if(sequence[i] > root)           //如果大于根节点，说明是右子树
            break;

    int j = i;
    for(;j < length - 1;++j)
        if(sequence[j] < root)           //如果右子树的节点小于根节点，不符合搜索树特点
            return false;

    bool left = true;                    //标志左子树是否为搜索树
    if(i > 0)
        left = VerifySequenceOfBST(sequence,i);  //对左子树进行判断，是否符合搜索树特点

    bool right = true;                   //标志右子树是否为搜索树
    if(i < length - 1)
        left = VerifySequenceOfBST(sequence + i,length - i - 1);//对右子树进行判断，是否符合搜索树特点
    return (left&&right);
}
//非递归实现，更简单
template<class T>
bool VerifyBinarySearchTree(vector<T> sequence)
{
    int i = 0;                  //用来遍历序列
    int size = sequence.size(); //序列的长度
    if(size <= 0)   return false;
    while(--size)               //对每个元素为根节点进行判断
    {
        while(sequence[i++] < sequence[size]);  //从头判断根节点之前的节点是否满足搜索树条件
        while(sequence[i++] > sequence[size]);

        if(i < size)            //i小于size，说明存在不满足条件的点
            return false;
        i = 0;
    }
    return true;                //如果全部满足条件，则说明是二叉搜索树
}
int main()
{
    cout << "binary search tree recruisely test" << endl;
    int sequence1[7] = {5,7,6,9,11,10,8};
    int sequence2[4] = {7,4,6,5};
    cout << VerifySequenceOfBST(sequence1,7) << endl;
    cout << VerifySequenceOfBST(sequence2,4) << endl;

    cout << "binary search tree common test" << endl;
    vector<int> sequence3(sequence1,sequence1+7);
    vector<int> sequence4(sequence2,sequence1+7);
    cout << VerifyBinarySearchTree(sequence3)<< endl;
    cout << VerifyBinarySearchTree(sequence4)<< endl;
    return 0;
}
