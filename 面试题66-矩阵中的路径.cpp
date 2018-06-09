/*******************************/
//�����е�·��
/*******************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool hasPathCore(char* matrix, int rows, int cols, int row, int col,
                 char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')    //�Ѿ�ƥ����str
        return true;

    bool hasPath = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols
       && matrix[row * cols + col] == str[pathLength]
       && !visited[row * cols + col])
    {   //�����ǰ��matrix�е�Ԫ�غ�str[pathlength]ƥ�䣬
        //�����Ѱ����һ��Ԫ�أ�����pathlength++��
        //ָ����һ��Ҫƥ����ַ�,����visited����Ӧ��λ����1����ʾ�Ѿ����ʹ�
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

    bool *visited = new bool[rows * cols]; //�����;��󣬱�ʶ�Ƿ��Ѿ����������
    memset(visited, 0, rows * cols);

    int pathLength = 0;
    //��matrix[rows][cols]��ͷ��ƥ��str���ж��Ƿ����ҵ�һ������str��·��
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

    delete[] visited;           //�ͷſռ�

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

