/************************************/
//统计数组中出现次数超过一半的数字
/************************************/
#include<iostream>
using namespace std;

//打印数组
void show(int *L,int length)
{
    for(int m = 0;m < length; m++) //因为是从L[1]开始存储的没所以从L[1]开始输出；
        cout << L[m] << " ";
    cout << endl;
}

bool g_bInputInvalid = false;        //标志是否是有效输入
//检查是否是有效输入
bool CheckInvalidArray(int* numbers,int length)
{
    g_bInputInvalid = false;
    if(numbers == NULL || length <= 0)
        g_bInputInvalid = true;

    return g_bInputInvalid;
}
//以numbers[start]为界限，将数组左右分开
int Partition(int* numbers, int length, int start, int end)
{
    int pivotkey = numbers[start];
    while(start < end)
    {
        while(start < end && numbers[end] >= pivotkey)    //从后往前找到第一个比pivotkey小的值，然后和pivotkey交换
            end--;
        swap(numbers[start], numbers[end]);

        while(start < end && numbers[start] <= pivotkey)  //从前往后找到第一个比pivotkey大的值，然后和pivotkey交换
            start++;
        swap(numbers[start], numbers[end]);
    }
}
//检查number的位置是否超过数组numbers[]的一半
bool CheckMoreThanHalf(int* numbers,int length, int number)
{
    int times = 0;                           //记录出现的次数
    for(int i = 0;i < length;i++)
        if(numbers[i] == number)
            times++;
    bool isMoreThanHalf = true;
    if(times * 2 <= length)                  //如果没有超过一半
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
}
//统计超过一半的数字
int MoreThanHalfNum(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))   //检查是否是有效输入，不是直接返回
        return 0;

    int middle = length >> 1;                //数组的中间位置
    int start = 0;                            //开始位置
    int end = length - 1;                    //结束位置
    int index = Partition(numbers, length, start, end);
    while(index != middle)
    {
        if(index > middle)
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
    int result = numbers[middle];            //取中间的数
    if(!CheckMoreThanHalf(numbers, length, result)) //检查result是否满足条件
        return 0;
    return result;
}
/******************************************/
//根据数组特点找出O(n)的算法
/******************************************/
int MoreThanHalfNum2(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))   //检查是否是有效输入，不是直接返回
        return 0;

    int result = numbers[0];
    int times = 1;
    for(int i = 1;i < length;i++)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }

    if(!CheckMoreThanHalf(numbers, length, result)) //检查result是否满足条件
        return 0;
    return result;
}
int MoreThanHalfNum3(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))   //检查是否是有效输入，不是直接返回
        return 0;
    int times = 0;
    int num_old , num_new = 0;
    int result = numbers[0];
    for(int i = 0;i < length;i++)
    {
        num_old = numbers[i];
        num_new = numbers[i + 1];
        if(num_old == num_new)
        {
            times++;
            if(times > 0)
                result = num_new;
        }
        else
            times--;
    }
    if(!CheckMoreThanHalf(numbers, length, result)) //检查result是否满足条件
        return 0;
    return result;
}
int main()
{
    int numbers[] = {1,0,1,0,1,0,1,0,1};
    int numbers2[] = {1,0,1};
    int result = MoreThanHalfNum(numbers,3);
    //cout << "数组中出现次数超过一半的数字是：" << result << endl;
    result = MoreThanHalfNum2(numbers2,13);
    cout << "数组中出现次数超过一半的数字是：" << result << endl;

    result = MoreThanHalfNum3(numbers2,3);
    cout << "数组中出现次数超过一半的数字是：" << result << endl;
    return 0;
}
