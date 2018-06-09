/************************************/
//ͳ�������г��ִ�������һ�������
/************************************/
#include<iostream>
using namespace std;

//��ӡ����
void show(int *L,int length)
{
    for(int m = 0;m < length; m++) //��Ϊ�Ǵ�L[1]��ʼ�洢��û���Դ�L[1]��ʼ�����
        cout << L[m] << " ";
    cout << endl;
}

bool g_bInputInvalid = false;        //��־�Ƿ�����Ч����
//����Ƿ�����Ч����
bool CheckInvalidArray(int* numbers,int length)
{
    g_bInputInvalid = false;
    if(numbers == NULL || length <= 0)
        g_bInputInvalid = true;

    return g_bInputInvalid;
}
//��numbers[start]Ϊ���ޣ����������ҷֿ�
int Partition(int* numbers, int length, int start, int end)
{
    int pivotkey = numbers[start];
    while(start < end)
    {
        while(start < end && numbers[end] >= pivotkey)    //�Ӻ���ǰ�ҵ���һ����pivotkeyС��ֵ��Ȼ���pivotkey����
            end--;
        swap(numbers[start], numbers[end]);

        while(start < end && numbers[start] <= pivotkey)  //��ǰ�����ҵ���һ����pivotkey���ֵ��Ȼ���pivotkey����
            start++;
        swap(numbers[start], numbers[end]);
    }
}
//���number��λ���Ƿ񳬹�����numbers[]��һ��
bool CheckMoreThanHalf(int* numbers,int length, int number)
{
    int times = 0;                           //��¼���ֵĴ���
    for(int i = 0;i < length;i++)
        if(numbers[i] == number)
            times++;
    bool isMoreThanHalf = true;
    if(times * 2 <= length)                  //���û�г���һ��
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
}
//ͳ�Ƴ���һ�������
int MoreThanHalfNum(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))   //����Ƿ�����Ч���룬����ֱ�ӷ���
        return 0;

    int middle = length >> 1;                //������м�λ��
    int start = 0;                            //��ʼλ��
    int end = length - 1;                    //����λ��
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
    int result = numbers[middle];            //ȡ�м����
    if(!CheckMoreThanHalf(numbers, length, result)) //���result�Ƿ���������
        return 0;
    return result;
}
/******************************************/
//���������ص��ҳ�O(n)���㷨
/******************************************/
int MoreThanHalfNum2(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))   //����Ƿ�����Ч���룬����ֱ�ӷ���
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

    if(!CheckMoreThanHalf(numbers, length, result)) //���result�Ƿ���������
        return 0;
    return result;
}
int MoreThanHalfNum3(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))   //����Ƿ�����Ч���룬����ֱ�ӷ���
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
    if(!CheckMoreThanHalf(numbers, length, result)) //���result�Ƿ���������
        return 0;
    return result;
}
int main()
{
    int numbers[] = {1,0,1,0,1,0,1,0,1};
    int numbers2[] = {1,0,1};
    int result = MoreThanHalfNum(numbers,3);
    //cout << "�����г��ִ�������һ��������ǣ�" << result << endl;
    result = MoreThanHalfNum2(numbers2,13);
    cout << "�����г��ִ�������һ��������ǣ�" << result << endl;

    result = MoreThanHalfNum3(numbers2,3);
    cout << "�����г��ִ�������һ��������ǣ�" << result << endl;
    return 0;
}
