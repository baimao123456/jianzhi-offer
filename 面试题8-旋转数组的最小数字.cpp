/*********************************/
//������8-��ת�����е���С����
/*********************************/
#include<iostream>
using namespace std;
/*****************************/
//��������
/*****************************/
//��data������ĩβԪ����Ϊ��Ԫ(pivot element),����Ԫ������data���ҷֿ���������Ԫ���ڵ�λ��
template<class T>
int Partition(T data[],int start,int end)
{
    if(data == NULL || start == end)  //�������Ϊ�գ�ֱ�ӷ���
        cout << "data is empty";

    T x = data[end];                //������ĩβԪ����Ϊ��Ԫ
    int small = start - 1;                //data[i]֮ǰ��������xС
    for(int j = start;j < end;j++)    //����xС��ֵ�ŵ�ǰ��
    {
        if(data[j] <= x)
        {
            small ++;
            swap(data[small],data[j]);
        }
    }
    swap(data[small+1],data[end]);   //����Ԫ���ں��ʵ�λ�ã����ý�����ֿ�
    return small+1;
}
//���ѡ����Ԫ
template<class T>
int Random_Partition(T data[],int start,int end)
{
    int index = rand()%(end-start+1)+start;   //����һ�� start��end�������
    swap(data[index],data[end]);              //�����ѡ���Ԫ�طŵ�����ĩβ����Ϊ
    return Partition(data,start,end);         //������Ԫ������
}
//��������
template<class T>
void Qsort(T data[],int start,int end)
{
    if(start < end)
    {
        //int q = Partition(data,start,end);      //������ĩβ��Ϊ��Ԫ
        int q = Random_Partition(data,start,end); //���ѡ����Ԫ
        Qsort(data,start,q - 1);                  //�ݹ齫��Ԫ֮ǰ�ı���ԪС��Ԫ���ٴν��л���
        Qsort(data,q + 1,end);                    //�ݹ齫��Ԫ֮��ı���Ԫ���Ԫ���ٴν��л���
    }
}
/************************************/
//����hash������������
/***********************************/
void SortAges(int ages[],int length)
{
    if(ages == NULL || length <= 0) //�������agesΪ�գ�����lengthΪ0
        return;
    const int oldestAge = 99;          //�������Ϊ99��
    int timesOfAge[oldestAge+1] = {0}; //����һ���������洢ÿ��������ֵĴ���
    for(int i = 0;i < length;++i)      //��¼ÿ��������ֵĴ���
    {
        int age =ages[i];
        if(age < 0 || age > oldestAge)
            cout << "age is not in right range!" << endl;
        ++timesOfAge[age];
    }
    int index = 0;
    for(int i = 0;i < oldestAge;i++)   //ĳ������ּ��Σ�����ages����ظ����Σ��൱��������
    {
        for(int j = 0;j < timesOfAge[i];++j)
        {
            ages[index] = i;
            ++index;
        }
    }
}
/*****************************/
//��ת�������С����
/*****************************/
//������Һ���,����numbers[index1:index2]����СԪ��
template<class T>
int MinInOrder(T* numbers,int index1,int index2)
{
    T result = numbers[index1];
    for(int i = index1 + 1;i < index2;i++)
        if(result > numbers[i])
        result = numbers[i];
    return result;
}
//���ö��ֲ��ҵ�˼��,������ת�����е���СԪ��
template<class T>
int Min(T *numbers,int length)
{
    if(numbers == NULL || length < 0)
        cout << "Invalid paragramers" << endl;
    int index1 = 0;                 //ǰ�ߵĵ������е����һ��Ԫ��
    int index2 = length - 1;        //��ߵĵ������еĵ�һ��Ԫ��
    int indexMid = index1;          //��ʼ��indexMinΪindex1����ֹ��ת0��Ԫ�ص����棬���������鱾������
    while(numbers[index1] >= numbers[index2])
    {
        if((index2 - index1) == 1)  //��������������Ԫ�أ�����СԪ�ؾ��Ǻ�����ĵ�һ��Ԫ��
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;             //���ö��ֲ��ҵ�˼�룬��һ����С���ҵķ�Χ
        //����±�Ϊindex1��index�Լ�indexMin��ֵ��ͬ
        //��ֻ��˳�����
        if(numbers[index1] == numbers[index2] &&
           numbers[index1] == numbers[indexMid]&&
           numbers[indexMid] == numbers[index2])
            return MinInOrder(numbers,index1,index2);
        if(numbers[indexMid] >= numbers[index1])      //����м�Ԫ�ش���ǰ�������еĵ�һ��Ԫ�أ�˵��numbers[indexMin]����ǰ��������
            index1 = indexMid;
        else if(numbers[indexMid] <= numbers[index2]) //numbers[indexMin]���ں��������
            index2 = indexMid;
    }
    return numbers[indexMid];
}
int main()
{
    /*****************************/
    //�����������
    /*****************************/
    int a[8] = {2,8,7,1,3,5,6,4};
    Qsort(a,0,8-1);
    for(int i = 0;i < 8; i++)
    {
        cout << a[i] <<',';
    }
    cout << endl;
    /*****************************/
    //hash�������������
    /*****************************/
    int ages[15] = {0,1,11,22,51,15,24,32,3,9,55,15,32,39,11};
    SortAges(ages,15);
    for(int i = 0;i < 15; i++)
    {
        cout << ages[i] <<',';
    }
    cout << endl;
    /*****************************/
    //��ת�������С���ֲ���
    /*****************************/
    int b[5] = {3,4,5,1,2};
    cout << Min(b,5) << endl;
    return 0;
}
