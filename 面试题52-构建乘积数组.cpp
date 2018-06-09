/**************************/
//构建乘积数组
/**************************/
#include <iostream>
#include <vector>
using namespace std;
void multiply(const vector<double>& array1, vector<double>& array2)
{
    int length1 = array1.size();
    int length2 = array2.size();

    if(length1 == length2 && length2 > 1)
    {
        array2[0] = 1;
        for(int i = 1; i < length1 ; ++i)    //从上到下依次计算
        {
            array2[i] = array2[i - 1] * array1[i - 1];
        }

        double temp = 1;
        for(int i = length1 - 2; i >= 0; --i) //从下到上计算
        {
            temp *= array1[i + 1];
            array2[i] *= temp;
        }
    }
}
int main()
{
    vector<double> array1 = {1,2,3,4,5,6};
    vector<double> array2 = {0,0,0,0,0,0};
    multiply(array1, array2);

    for(int i = 0;i < array2.size();i++)
    {
        cout << array2[i] << ',';
    }
    return 0;
}
