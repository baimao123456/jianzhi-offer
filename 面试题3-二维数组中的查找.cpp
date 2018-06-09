/*******************/
//������3����ά�����еĲ���
/*******************/
#include <iostream>

using namespace std;
int GetSize(int data[])
{
    return sizeof(data);
}
/****************************/
//������3
/****************************/
//��ӡ�����е�Ԫ��
void show(int *matrix,const int rows,const int columns)
{
    int i = 0;
    for(int row = 0;row < rows;++row)
    {
        for(int column = 0;column < columns;++column)
            cout << matrix[row * columns + column] << ',';
        cout << endl;
    }
    cout << endl;
}
//�ж�number�Ƿ�������������
bool Find(int *matrix,int rows,int columns,int number)
{
    //�����Ͻǽ��в���
    bool found = false;
    if(matrix != NULL && rows > 0 && columns > 0) //�����ά���鲻�ǿ�
    {
        int row = 0;
        int column = columns - 1;                 //�������н��в���
        while(row < rows && column >= 0)          //�������Ԫ��û�в���
        {
            //cout << matrix[row * columns + column] << endl;
            if(matrix[row * columns + column] == number)     //����ҵ�number��������ѭ����ֹͣ����
            {
                found = true;
                break;
            }
            else if(matrix[row * columns + column] > number) //���number���ڵ�ǰ��Ԫ�أ���ɾ�����У���Ϊ������������number
                --column;
            else
                ++row;
        }
    }
    return found; //���ش������ı�־  true������  false��������
}
int main()
{
    int data1[] = {1,2,3,4,5};
    int size1 = sizeof(data1);  //�����sizeof������������Ĵ�С  5*int�Ŀռ�

    int *data2 = data1;
    int size2 = sizeof(data2);  //int��ָ��Ŀռ��С

    int size3 = GetSize(data1); //GetSize���ݵĲ�����ʵҲ�Ǹ�ָ��

    cout << size1 << ' '<< size2<< ' ' << size3 << endl;
    /********************************************/
    int matrix[16] = {1,2,8,9,
                      2,4,9,12,
                      4,7,10,13,
                      6,8,11,15};
    cout  << Find(matrix,4,4,6) <<endl;
    show(matrix,4,4);
    return 0;
}
