/*******************************/
//矩阵中的路径
/*******************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool hasPathCore(char* matrix, int rows, int cols, int row, int col,
                 char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')    //已经匹配完str
        return true;

    bool hasPath = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols
       && matrix[row * cols + col] == str[pathLength]
       && !visited[row * cols + col])
    {   //如果当前的matrix中的元素和str[pathlength]匹配，
        //则继续寻找下一个元素，并将pathlength++，
        //指向下一个要匹配的字符,并在visited中相应的位置置1，表示已经访问过
        ++pathLength;
        visited[row * cols + col] = true;

        hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
                              str,pathLength, visited)
                ||hasPathCore(matrix, rows, cols, row - 1, col,
                              str,pathLength, visited)
                ||hasPathCore(matrix, rows, cols, row, col + 1,
                              str,pathLength, visited)
                ||hasPathCore(matrix, rows, cols, row + 1, col,
                              str,pathLength, visited);
        if(!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }
    return hasPath;
}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
        return false;

    bool *visited = new bool[rows * cols]; //布尔型矩阵，标识是否已经进入过矩阵
    memset(visited, 0, rows * cols);

    int pathLength = 0;
    //以matrix[rows][cols]开头来匹配str，判断是否能找到一条符合str的路径
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            if(hasPathCore(matrix, rows, cols, row, col, str,
                           pathLength, visited))
            {
                return true;
            }
        }
    }

    delete[] visited;           //释放空间

    return false;
}
int main()
{
    char matrix[] = "ABCESFCSADEE";
    //char* str = "ABCCED";
    char* str = "ABCD";
    cout << hasPath(matrix, 3, 4, str);
    return 0;
}

