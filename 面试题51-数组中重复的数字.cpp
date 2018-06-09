/************************/
//数组中重复的数字
/************************/
#include <iostream>
#include <vector>
using namespace std;
bool duplicate(vector<int> data, int& duplication)
{
    int length = data.size();
    if(length <= 0)
        return false;

    for(int i = 0; i < length ;++i)    //数值不满足条件
    {
        if(data[i] < 0 || data[i] > length - 1)
            return false;
    }
    for(int i = 0; i < length ; ++i)
    {
        while(data[i] != i)         //一直在i处判断，直到满足条件
        {
            if(data[i] == data[data[i]]) //如果i位置上存在相同的值，说明重复了
            {
                duplication = data[i];
                return true;
            }
            swap(data[i], data[data[i]]);
        }
    }
    return false;
}
int main()
{
    int d;
    vector<int> number = {3,1,2,4,2,5,3};
    duplicate(number,d);
    cout << d << endl;
    return 0;
}
