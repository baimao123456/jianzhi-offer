/*********************************/
//连续子数组的最大和
/*********************************/
#include <iostream>
using namespace std;
int FindGreatSumOfSubArray(int* pData, int length)
{
    if(pData == NULL || length <= 0)
        return 0;
    int curSum = 0;
    //int greatSum = 0x80000000;
    int greatSum = 0;
    for(int i = 0;i < length;++i)
    {
        if(curSum <= 0)          //如果当前的子数组的和小于0，最大和肯定不是之前的序列，必须则从下个数开始累加
            curSum = pData[i];
        else
            curSum += pData[i];  //如果和大于0，则直接相加

        if(curSum > greatSum)
            greatSum = curSum;
    }
    return greatSum;
}
int main()
{
    int data[] = {1,-2,3,10,-4,7,2,-5};
    cout << "the max sum of sub arrat is :" << endl;
    cout << FindGreatSumOfSubArray(data,sizeof(data)/sizeof(int));
    return 0;
}
