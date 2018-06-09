/************************/
//�����������ĺ����������
/************************/
#include<iostream>
#include"BinaryTree.h"
#include<vector>
using namespace std;
//�ݹ�ʵ��
template<class T>
bool VerifySequenceOfBST(T sequence[],int length)
{
    if(sequence == NULL || length <= 0)
        return false;
    T root = sequence[length - 1];       //���ڵ�

    //�ڶ������������������Ľڵ��С�ڸ��ڵ�
    int i = 0;
    for(;i < length - 1;++i)
        if(sequence[i] > root)           //������ڸ��ڵ㣬˵����������
            break;

    int j = i;
    for(;j < length - 1;++j)
        if(sequence[j] < root)           //����������Ľڵ�С�ڸ��ڵ㣬�������������ص�
            return false;

    bool left = true;                    //��־�������Ƿ�Ϊ������
    if(i > 0)
        left = VerifySequenceOfBST(sequence,i);  //�������������жϣ��Ƿ�����������ص�

    bool right = true;                   //��־�������Ƿ�Ϊ������
    if(i < length - 1)
        left = VerifySequenceOfBST(sequence + i,length - i - 1);//�������������жϣ��Ƿ�����������ص�
    return (left&&right);
}
//�ǵݹ�ʵ�֣�����
template<class T>
bool VerifyBinarySearchTree(vector<T> sequence)
{
    int i = 0;                  //������������
    int size = sequence.size(); //���еĳ���
    if(size <= 0)   return false;
    while(--size)               //��ÿ��Ԫ��Ϊ���ڵ�����ж�
    {
        while(sequence[i++] < sequence[size]);  //��ͷ�жϸ��ڵ�֮ǰ�Ľڵ��Ƿ���������������
        while(sequence[i++] > sequence[size]);

        if(i < size)            //iС��size��˵�����ڲ����������ĵ�
            return false;
        i = 0;
    }
    return true;                //���ȫ��������������˵���Ƕ���������
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
