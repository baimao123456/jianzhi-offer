
/************************************/
//顺时针打印矩阵
/************************************/
#include<iostream>
#include<string.h>
using namespace std;
//打印1维矩阵
void PrintNumber(char *number)
{
    int nLength = strlen(number);          //数字的长度
    for(int i = 0;i < nLength;i++)
        cout << number[i];
    cout << endl;
}
void PrintMatrixInCircle(int** numbers,int columns,int rows,int start)
{
    int endX = columns - 1 - start;    //终止行坐标值
    int endY = rows - 1 - start;       //终止列坐标值

    //从左到右打印一行
    for(int i = start;i <= endX;++i)
        cout<<  numbers[start][i] << ' ';
    cout << endl;

    //从上到下打印一列
    if(start < endY)
    {
        for(int i = start + 1;i <= endY;++i)
            cout << numbers[i][endX] << ' ';
    }
    cout << endl;

    //从右到左打印一行
    if(start < endX && start < endY)
    {
        for(int i = endX - 1;i >= start;--i)
            cout << numbers[endY][i] << ' ';
    }
    cout << endl;
    //从下到上打印一行
    if(start < endX && start < endY - 1)
    {
        for(int i = endY - 1;i >= start + 1;--i)
            cout << numbers[endY][i] << ' ';
    }
    cout << endl;
}
void PrintMatrixClockwisely(int** numbers,int columns,int rows)
{
    if(numbers == NULL || columns <= 0 || rows <= 0)    //如果矩阵为空，或者行或列不大于0，直接返回
        return;

    int start = 0;  //打印矩阵的开始坐标，(0,0)(2,2)等
    while(columns > start * 2 && rows > start * 2)     //打印的边界条件
    {
        PrintMatrixInCircle(numbers,columns,rows,start);
        ++start;
    }
}
// ====================测试代码====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];      //开辟行向量空间
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];   //开辟列向量空间
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);

    /*for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
            cout << numbers[i][j] << ' ';
        cout << endl;
    }*/
    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}
int main()
{
    /*
    1
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}
