/**********************************/
//面试题--36 数组中的逆序对
/**********************************/
#include <iostream>
#include <vector>
using namespace std;
/*
//核心代码
int InversePairsCore(int* data, int* copy, int start, int end)
{
    if(start == end)
    {
        copy[start] = data[start];
        return 0;
    }

    int length = (end - start) >> 1;

    int left = InversePairsCore(data, copy, start, start + length);
    int right = InversePairsCore(data, copy, start + length + 1, end);

    int i = start + length;          //i初始化为前半段的最后一个数字的下标
    int j = end;                     //j初始化为后半段的最后一个数字的下标

    int indexCopy = end;
    int count = 0;

    while(i >= start && j >= start + length + 1)
    {
        if(data[i] > data[j])                  //是逆序,说明前半段的数比后半段的都要大
        {
            copy[indexCopy--] = data[i--];     //将较大的值放在copy中
            count += j - start - length;       //后半段均小于前半段，所以逆序的数量为 （后半段的长度）
        }
        else
        {                                      //说明不是逆序，直接将最大值放到copy最后
            copy[indexCopy--] = data[j--];
        }
    }

    // 将数组中剩余的元素放进辅助数组中去，两个只会执行一个
    while(i >= start)   copy[indexCopy--] = data[i--];
    while(j >= start + length + 1)   copy[indexCopy--] = data[j--];

    //将排序好、合并好的数组重新赋值给data，依旧使用copy作为辅助数组
    for(i = start; i <= end; i++)
        data[i] = copy[i];

    return left + right + count;
}
int InversePairs(int* data, int length)
{
    if(data == NULL || length < 0)
        return 0;

    int* copy = new int[length];

    for(int i = 0;i < length; i++)
        copy[i] = data[i];

    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;

    return count;
}*/
int InversePairsCore(vector<int>& data, int start, int end)
{
    if(start >= end)                    //
        return 0;

    int mid = (start + end) >> 1;
    vector<int> copy(data);             //辅助数组

    int left_count = InversePairsCore(data, start, mid);
    int right_count = InversePairsCore(data, mid + 1, end);

    int i = mid;                        //i 初始化为前半段的最后一个数字的下标
    int j = end;                        //j 初始化为后半段的最后一个数字的下标
    int indexCopy = end;                //记录copy元素的索引
    int count = 0;

    while(i >= start && j >= mid + 1)
    {
        if(data[i] > data[j])
        {
            copy[indexCopy--] = data[i--];
            count += j - mid;
        }
        else
            copy[indexCopy--] = data[j--];
    }

    //将数组中剩余的元素放进辅助数组中去，两个只会执行一个
    while(i >= start)  copy[indexCopy--] = data[i--];
    while(j >= mid + 1)  copy[indexCopy--] = data[j--];

    //将排序好、合并好的数组重新赋值给data，依旧使用copy作为辅助数组
    for(int i = start; i <= end; i++)
        data[i] = copy[i];

    return left_count + right_count + count;
}
int InversePairs(vector<int>& data)
{
    int length = data.size();

    if(length < 0)
        return 0;

    return InversePairsCore(data, 0, length - 1);

}
int main()
{
    cout << "helho world" << endl;
    int number[] = {7, 5, 6, 4, 6};
    vector<int> numbers = {7, 5, 6, 4, 6};
    cout << InversePairs(numbers);
    return 0;
}

