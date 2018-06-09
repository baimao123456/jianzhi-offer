/*******************************/
//机器人的运动范围
/*******************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
//返回number的各位上的和
int getDigitSum(int number)
{
    int sum = 0;
    while(number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
//检查是否能进入方格 visited[row * cols + col]
bool check(int threshold, int rows, int cols,
                     int row, int col, bool* visited)
{
    if(row >= 0 && row <rows && col >= 0 && col < cols
       && getDigitSum(row) + getDigitSum(col) <= threshold
       && !visited[row * cols + col])
        return true;
    return false;
}
int movingCountCore(int threshold, int rows, int cols,
                     int row, int col, bool* visited)
{
    int count = 0;
    if(check(threshold, rows, cols, row, col, visited))
    {
        visited[row * cols + col] = true;

        count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col + 1, visited);
    }
    return count;
}
int movingCount(int threshold, int rows, int cols)
{
    bool *visited = new bool[rows * cols]; //布尔型矩阵，标识是否已经进入过矩阵
    memset(visited, false, rows * cols);

    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

    delete[] visited;           //释放空间

    return count;
}
int main()
{
    cout << movingCount(5,10,10);
    return 0;
}


