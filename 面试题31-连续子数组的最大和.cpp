/*********************************/
//���������������
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
        if(curSum <= 0)          //�����ǰ��������ĺ�С��0�����Ϳ϶�����֮ǰ�����У���������¸�����ʼ�ۼ�
            curSum = pData[i];
        else
            curSum += pData[i];  //����ʹ���0����ֱ�����

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
