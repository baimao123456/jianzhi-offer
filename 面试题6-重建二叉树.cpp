
/*************************************/
//面试题6-重建二叉树
/*************************************/
#include<iostream>
#include<exception>
using namespace std;

//树节点定义
template<class T>
struct BinaryTreeNode
{
    T value;             //节点元素
    BinaryTreeNode* pLeft;     //左节点
    BinaryTreeNode* pRight;    //右节点
};
//根据前序遍历和中序遍历的序列中确定根节点的值，左子树节点的值和右子树节点的值
//startPreorder, endPreorder,startInorder, endInorder全部都是数组的地址
template<class T>
BinaryTreeNode<T>* ConstructCore
(
    T* startPreorder, T* endPreorder,
    T* startInorder, T* endInorder
)
{
    //找到根节点--前序遍历序列的第一个数字就是根节点的值
    T rootValue = startPreorder[0];
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(); //构造根节点
    root->value = rootValue;
    root->pLeft = root->pRight = NULL;

    if(startPreorder == endPreorder)             //只有一个节点，即根节点
    {
        if(startInorder ==endInorder
            && *startPreorder == *startInorder)
                return root;
        else
            //throw exception("Invalid input.");
            cout << "Invalid input." << endl;
    }
    /************找到根节点位置**************/
    int* rootInorder = startInorder;       //保存根节点的指针值，是一个地址
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    if(rootInorder == endInorder && *rootInorder != rootValue)
        cout << "Invalid input." << endl;
    int leftlength = rootInorder - startInorder;    //计算出左子树节点的个数

    int* leftPreorderEnd = startPreorder + leftlength;  //左子树节点的结束位置
    if(leftlength > 0)    //如果左子树的节点数目不是0，则构建左子树
    {
        //递归构建左子树
        root->pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,
                                    startInorder,rootInorder - 1);
    }
    if(leftlength < endPreorder - startPreorder)  //如果leftlength等于节点的数组，说明此根节点只有左树
    {
        //递归构建右子树
        root->pRight = ConstructCore(leftPreorderEnd + 1,endPreorder,
                                     rootInorder + 1,endInorder);
    }
    return root;
}
//根据前序遍历和中序遍历来重建树
//参数 preorder和inorder是存储遍历节点的数组，length是节点的个数
template<class T>
BinaryTreeNode<T>* Construct(T* preorder,T* inorder,int length)
{
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    return ConstructCore(preorder,preorder + length - 1,
                         inorder,inorder +length - 1);
}
//前序遍历
template<class T>
void Preorder_print(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    cout << pNode->value << ',';
    Preorder_print(pNode->pLeft);
    Preorder_print(pNode->pRight);
}
//中序遍历
template<class T>
void Inorder_print(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    Inorder_print(pNode->pLeft);
    cout << pNode->value << ',';
    Inorder_print(pNode->pRight);
}
//后序遍历
template<class T>
void Postorder_print(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    Postorder_print(pNode->pLeft);
    Postorder_print(pNode->pRight);
    cout << pNode->value << ',';
}
int main()
{
    int preorder[] = {1,2,4,7,3,5,6,8};
    int inorder[] = {4,7,2,1,5,3,8,6};
    BinaryTreeNode<int>* tree = Construct(preorder,inorder,8);
    Preorder_print(tree); cout << endl;
    Inorder_print(tree);  cout << endl;
    Postorder_print(tree);cout << endl;
    return 0;
}
