/*************************************/
//���� k �����������г��ֵĴ���
/*************************************/
#include <iostream>
#include <vector>
using namespace std;
//�ҵ���һ��k
int GetFirst(vector<int> data, int k, int start, int end)
{
    if(start > end)
        return -1;

    int middleIndex = (start + end) >> 1;//�м�Ԫ�ص�λ��
    int middleData = data[middleIndex];

    if(middleData == k)                  //����м�ֵ���õ��� k ��һ���ж� k �Ƿ��ǵ�һ��k
    {
        if((middleIndex > 0 && data[middleIndex - 1] != k)
           || middleIndex == 0)          //����ǵ�һ��k����kλ����Ԫ�أ�ֱ�ӷ���k���ڵ�λ��
            return middleIndex;
        end =  middleIndex - 1;          //������ǵ�һ��k���������data[start:middleIndex - 1]Ѱ��
    }
    else if(middleData > k)              //����м�ֵ����k���������data[start:middleIndex - 1]Ѱ��
        end = middleIndex - 1;
    else
        start = middleIndex + 1;         //����м�ֵС��k��˵����һ��k�ں�ߣ���ʱ��data[middleIndex + 1:end]Ѱ��

    return GetFirst(data, k, start, end);
}
//�ҵ���һ��k
int GetLast(vector<int> data, int k, int start, int end)
{
    if(start > end)
        return -1;

    int length = data.size();            //����data�ĳ���
    int middleIndex = (start + end) >> 1;//�м�Ԫ�ص�λ��
    int middleData = data[middleIndex];

    if(middleData == k)                  //����м�ֵ���õ��� k ��һ���ж� k �Ƿ�������k
    {
        if((middleIndex < length - 1 && data[middleIndex + 1] != k)
           || middleIndex == length - 1) //���������k��ֱ�ӷ���k���ڵ�λ��
            return middleIndex;
        else
            start = middleIndex + 1;     //������ǵ�һ��k���������data[start:middleIndex - 1]Ѱ��
    }
    else if(middleData < k)              //����м�ֵ���� k���������data[start:middleIndex - 1]Ѱ��
        start = middleIndex + 1;
    else
        end = middleIndex - 1;           //����м�ֵС��k��˵����һ��k�ں�ߣ���ʱ��data[middleIndex + 1:end]Ѱ��

    return GetLast(data, k, start, end);
}
int GetNumberOfK(vector<int> data, int k)
{
    int number = 0;                      //k�ĸ���
    int length = data.size();            //����ĳ���
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
