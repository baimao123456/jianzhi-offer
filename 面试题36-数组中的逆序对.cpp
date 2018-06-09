/**********************************/
//������--36 �����е������
/**********************************/
#include <iostream>
#include <vector>
using namespace std;
/*
//���Ĵ���
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

    int i = start + length;          //i��ʼ��Ϊǰ��ε����һ�����ֵ��±�
    int j = end;                     //j��ʼ��Ϊ���ε����һ�����ֵ��±�

    int indexCopy = end;
    int count = 0;

    while(i >= start && j >= start + length + 1)
    {
        if(data[i] > data[j])                  //������,˵��ǰ��ε����Ⱥ��εĶ�Ҫ��
        {
            copy[indexCopy--] = data[i--];     //���ϴ��ֵ����copy��
            count += j - start - length;       //���ξ�С��ǰ��Σ��������������Ϊ �����εĳ��ȣ�
        }
        else
        {                                      //˵����������ֱ�ӽ����ֵ�ŵ�copy���
            copy[indexCopy--] = data[j--];
        }
    }

    // ��������ʣ���Ԫ�طŽ�����������ȥ������ֻ��ִ��һ��
    while(i >= start)   copy[indexCopy--] = data[i--];
    while(j >= start + length + 1)   copy[indexCopy--] = data[j--];

    //������á��ϲ��õ��������¸�ֵ��data������ʹ��copy��Ϊ��������
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
    vector<int> copy(data);             //��������

    int left_count = InversePairsCore(data, start, mid);
    int right_count = InversePairsCore(data, mid + 1, end);

    int i = mid;                        //i ��ʼ��Ϊǰ��ε����һ�����ֵ��±�
    int j = end;                        //j ��ʼ��Ϊ���ε����һ�����ֵ��±�
    int indexCopy = end;                //��¼copyԪ�ص�����
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

    //��������ʣ���Ԫ�طŽ�����������ȥ������ֻ��ִ��һ��
    while(i >= start)  copy[indexCopy--] = data[i--];
    while(j >= mid + 1)  copy[indexCopy--] = data[j--];

    //������á��ϲ��õ��������¸�ֵ��data������ʹ��copy��Ϊ��������
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

