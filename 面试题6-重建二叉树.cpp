
/*************************************/
//������6-�ؽ�������
/*************************************/
#include<iostream>
#include<exception>
using namespace std;

//���ڵ㶨��
template<class T>
struct BinaryTreeNode
{
    T value;             //�ڵ�Ԫ��
    BinaryTreeNode* pLeft;     //��ڵ�
    BinaryTreeNode* pRight;    //�ҽڵ�
};
//����ǰ����������������������ȷ�����ڵ��ֵ���������ڵ��ֵ���������ڵ��ֵ
//startPreorder, endPreorder,startInorder, endInorderȫ����������ĵ�ַ
template<class T>
BinaryTreeNode<T>* ConstructCore
(
    T* startPreorder, T* endPreorder,
    T* startInorder, T* endInorder
)
{
    //�ҵ����ڵ�--ǰ��������еĵ�һ�����־��Ǹ��ڵ��ֵ
    T rootValue = startPreorder[0];
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(); //������ڵ�
    root->value = rootValue;
    root->pLeft = root->pRight = NULL;

    if(startPreorder == endPreorder)             //ֻ��һ���ڵ㣬�����ڵ�
    {
        if(startInorder ==endInorder
            && *startPreorder == *startInorder)
                return root;
        else
            //throw exception("Invalid input.");
            cout << "Invalid input." << endl;
    }
    /************�ҵ����ڵ�λ��**************/
    int* rootInorder = startInorder;       //������ڵ��ָ��ֵ����һ����ַ
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    if(rootInorder == endInorder && *rootInorder != rootValue)
        cout << "Invalid input." << endl;
    int leftlength = rootInorder - startInorder;    //������������ڵ�ĸ���

    int* leftPreorderEnd = startPreorder + leftlength;  //�������ڵ�Ľ���λ��
    if(leftlength > 0)    //����������Ľڵ���Ŀ����0���򹹽�������
    {
        //�ݹ鹹��������
        root->pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,
                                    startInorder,rootInorder - 1);
    }
    if(leftlength < endPreorder - startPreorder)  //���leftlength���ڽڵ�����飬˵���˸��ڵ�ֻ������
    {
        //�ݹ鹹��������
        root->pRight = ConstructCore(leftPreorderEnd + 1,endPreorder,
                                     rootInorder + 1,endInorder);
    }
    return root;
}
//����ǰ�����������������ؽ���
//���� preorder��inorder�Ǵ洢�����ڵ�����飬length�ǽڵ�ĸ���
template<class T>
BinaryTreeNode<T>* Construct(T* preorder,T* inorder,int length)
{
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    return ConstructCore(preorder,preorder + length - 1,
                         inorder,inorder +length - 1);
}
//ǰ�����
template<class T>
void Preorder_print(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    cout << pNode->value << ',';
    Preorder_print(pNode->pLeft);
    Preorder_print(pNode->pRight);
}
//�������
template<class T>
void Inorder_print(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return;
    Inorder_print(pNode->pLeft);
    cout << pNode->value << ',';
    Inorder_print(pNode->pRight);
}
//�������
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
