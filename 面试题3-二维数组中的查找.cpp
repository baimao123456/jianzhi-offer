/*******************/
//面试题3，二维数组中的查找
/*******************/
#include <iostream>

using namespace std;
int GetSize(int data[])
{
    return sizeof(data);
}
/****************************/
//面试题3
/****************************/
//打印数组中的元素
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
//判断number是否在有序数组中
bool Find(int *matrix,int rows,int columns,int number)
{
    //从右上角进行查找
    bool found = false;
    if(matrix != NULL && rows > 0 && columns > 0) //如果二维数组不是空
    {
        int row = 0;
        int column = columns - 1;                 //从最右列进行查找
        while(row < rows && column >= 0)          //如果还有元素没有查找
        {
            //cout << matrix[row * columns + column] << endl;
            if(matrix[row * columns + column] == number)     //如果找到number，则跳出循环，停止查找
            {
                found = true;
                break;
            }
            else if(matrix[row * columns + column] > number) //如果number大于当前的元素，则删除此列，因为这列数都大于number
                --column;
            else
                ++row;
        }
    }
    return found; //返回存在与否的标志  true：存在  false：不存在
}
int main()
{
    int data1[] = {1,2,3,4,5};
    int size1 = sizeof(data1);  //这里的sizeof测量的是数组的大小  5*int的空间

    int *data2 = data1;
    int size2 = sizeof(data2);  //int型指针的空间大小

    int size3 = GetSize(data1); //GetSize传递的参数其实也是个指针

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
