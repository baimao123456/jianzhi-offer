/*************************************/
//����������һ���ڵ�
/*************************************/
#include <iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
    T value;                  //Ԫ��ֵ
    BinaryTreeNode* pLeft;    //��ڵ�
    BinaryTreeNode* pRight;   //�ҽڵ�
    BinaryTreeNode* pParent;  //���ڵ�

    BinaryTreeNode(){pLeft = pRight = pParent = NULL;}       //Ĭ�Ϲ��캯��
    BinaryTreeNode(const T& the_value):value(the_value)  //���캯��
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
//�������
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
//��������������һ���ڵ�
template<class T>
BinaryTreeNode<T>* GetNext(BinaryTreeNode<T>* pNode)
{
    if(pNode == NULL)
        return NULL;

    BinaryTreeNode<T>* pNext = NULL;
    if(pNode->pRight != NULL)       //����ڵ����������������һ���ڵ����������������ڵ�
    {
        BinaryTreeNode<T>* pRight = pNode->pRight; //���������ڵ�
        while(pRight->pLeft != NULL)
            pRight = pRight->pLeft;
        pNext = pRight;             //����ڵ�
    }
    else if(pNode->pParent != NULL) //�����ǰ�ڵ�û�����������Ҵ��ڸ��ڵ�
    {
        BinaryTreeNode<T>* pCurrent = pNode;
        BinaryTreeNode<T>* pParent = pNode->pParent;

        //�ҵ�һ���ڵ㣬��ǰ�ڵ��������ڵ��������
        while(pParent != NULL && pCurrent == pParent->pRight)
        {
            pCurrent = pParent;
            pParent = pParent->pParent;
        }
        pNext = pParent;              //���while���������㣬��һ�ڵ���ǵ�ǰ�ڵ�ĸ��ڵ�
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





