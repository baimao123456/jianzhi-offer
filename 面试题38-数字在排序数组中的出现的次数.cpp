/*************************************/
//数字 k 在排序数组中出现的次数
/*************************************/
#include <iostream>
#include <vector>
using namespace std;
//找到第一个k
int GetFirst(vector<int> data, int k, int start, int end)
{
    if(start > end)
        return -1;

    int middleIndex = (start + end) >> 1;//中间元素的位置
    int middleData = data[middleIndex];

    if(middleData == k)                  //如果中间值正好等于 k 进一步判断 k 是否是第一个k
    {
        if((middleIndex > 0 && data[middleIndex - 1] != k)
           || middleIndex == 0)          //如果是第一个k或者k位于首元素，直接返回k所在的位置
            return middleIndex;
        end =  middleIndex - 1;          //如果不是第一个k，则继续在data[start:middleIndex - 1]寻找
    }
    else if(middleData > k)              //如果中间值不是k，则继续在data[start:middleIndex - 1]寻找
        end = middleIndex - 1;
    else
        start = middleIndex + 1;         //如果中间值小于k，说明第一个k在后边，此时在data[middleIndex + 1:end]寻找

    return GetFirst(data, k, start, end);
}
//找到第一个k
int GetLast(vector<int> data, int k, int start, int end)
{
    if(start > end)
        return -1;

    int length = data.size();            //数组data的长度
    int middleIndex = (start + end) >> 1;//中间元素的位置
    int middleData = data[middleIndex];

    if(middleData == k)                  //如果中间值正好等于 k 进一步判断 k 是否是最后的k
    {
        if((middleIndex < length - 1 && data[middleIndex + 1] != k)
           || middleIndex == length - 1) //如果是最后的k，直接返回k所在的位置
            return middleIndex;
        else
            start = middleIndex + 1;     //如果不是第一个k，则继续在data[start:middleIndex - 1]寻找
    }
    else if(middleData < k)              //如果中间值大于 k，则继续在data[start:middleIndex - 1]寻找
        start = middleIndex + 1;
    else
        end = middleIndex - 1;           //如果中间值小于k，说明第一个k在后边，此时在data[middleIndex + 1:end]寻找

    return GetLast(data, k, start, end);
}
int GetNumberOfK(vector<int> data, int k)
{
    int number = 0;                      //k的个数
    int length = data.size();            //数组的长度
    if(length > 0)
    {
        int first = GetFirst(data, k, 0, length - 1);
        int last = GetLast(data, k, 0, length - 1);
        if(first > -1 && last > -1)
            number = last - first + 1;
    }
    return number;
}
int main()
{
    //vector<int> number = {1,2,3,3,3,3,4,5};
    vector<int> number = {1,3,3,3,3,3,3,5};
    cout << "the first k is : ";
    cout << GetFirst(number, 3, 0, 8) << endl;
    cout << "the last k is : ";
    cout << GetLast(number, 3, 0, 8) << endl;
    cout << "the total number of 3 is : ";
    cout << GetNumberOfK(number, 3) << endl;

    return 0;
}
