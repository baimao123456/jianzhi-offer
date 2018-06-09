/*********************************/
//面试题8-旋转数组中的最小数字
/*********************************/
#include<iostream>
using namespace std;
/*****************************/
//快速排序
/*****************************/
//将data数组以末尾元素作为主元(pivot element),以主元将数组data左右分开，返回主元所在的位置
template<class T>
int Partition(T data[],int start,int end)
{
    if(data == NULL || start == end)  //如果数组为空，直接返回
        cout << "data is empty";

    T x = data[end];                //将数组末尾元素作为主元
    int small = start - 1;                //data[i]之前的数都比x小
    for(int j = start;j < end;j++)    //将比x小的值放到前边
    {
        if(data[j] <= x)
        {
            small ++;
            swap(data[small],data[j]);
        }
    }
    swap(data[small+1],data[end]);   //将主元放在合适的位置，正好将数组分开
    return small+1;
}
//随机选择主元
template<class T>
int Random_Partition(T data[],int start,int end)
{
    int index = rand()%(end-start+1)+start;   //生成一个 start到end的随机数
    swap(data[index],data[end]);              //将随机选择的元素放到数组末尾，作为
    return Partition(data,start,end);         //返回主元的索引
}
//快速排序
template<class T>
void Qsort(T data[],int start,int end)
{
    if(start < end)
    {
        //int q = Partition(data,start,end);      //将数组末尾作为主元
        int q = Random_Partition(data,start,end); //随机选择主元
        Qsort(data,start,q - 1);                  //递归将主元之前的比主元小的元素再次进行划分
        Qsort(data,q + 1,end);                    //递归将主元之后的比主元大的元素再次进行划分
    }
}
/************************************/
//利用hash表，对年龄排序
/***********************************/
void SortAges(int ages[],int length)
{
    if(ages == NULL || length <= 0) //如果数组ages为空，或者length为0
        return;
    const int oldestAge = 99;          //最大年龄为99岁
    int timesOfAge[oldestAge+1] = {0}; //建立一个表，用来存储每个年龄出现的次数
    for(int i = 0;i < length;++i)      //记录每个年龄出现的次数
    {
        int age =ages[i];
        if(age < 0 || age > oldestAge)
            cout << "age is not in right range!" << endl;
        ++timesOfAge[age];
    }
    int index = 0;
    for(int i = 0;i < oldestAge;i++)   //某年龄出现几次，就在ages里边重复几次，相当于排序了
    {
        for(int j = 0;j < timesOfAge[i];++j)
        {
            ages[index] = i;
            ++index;
        }
    }
}
/*****************************/
//旋转数组的最小数字
/*****************************/
//按序查找函数,查找numbers[index1:index2]的最小元素
template<class T>
int MinInOrder(T* numbers,int index1,int index2)
{
    T result = numbers[index1];
    for(int i = index1 + 1;i < index2;i++)
        if(result > numbers[i])
        result = numbers[i];
    return result;
}
//利用二分查找的思想,查找旋转数组中的最小元素
template<class T>
int Min(T *numbers,int length)
{
    if(numbers == NULL || length < 0)
        cout << "Invalid paragramers" << endl;
    int index1 = 0;                 //前边的递增数列的最后一个元素
    int index2 = length - 1;        //后边的递增数列的第一个元素
    int indexMid = index1;          //初始化indexMin为index1，防止旋转0个元素到后面，即排序数组本身的情况
    while(numbers[index1] >= numbers[index2])
    {
        if((index2 - index1) == 1)  //如果数组仅有两个元素，则最小元素就是后递增的第一个元素
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;             //利用二分查找的思想，进一步缩小查找的范围
        //如果下标为index1和index以及indexMin的值相同
        //则只能顺序查找
        if(numbers[index1] == numbers[index2] &&
           numbers[index1] == numbers[indexMid]&&
           numbers[indexMid] == numbers[index2])
            return MinInOrder(numbers,index1,index2);
        if(numbers[indexMid] >= numbers[index1])      //如果中间元素大于前递增序列的第一个元素，说明numbers[indexMin]属于前递增序列
            index1 = indexMid;
        else if(numbers[indexMid] <= numbers[index2]) //numbers[indexMin]属于后递增序列
            index2 = indexMid;
    }
    return numbers[indexMid];
}
int main()
{
    /*****************************/
    //快速排序测试
    /*****************************/
    int a[8] = {2,8,7,1,3,5,6,4};
    Qsort(a,0,8-1);
    for(int i = 0;i < 8; i++)
    {
        cout << a[i] <<',';
    }
    cout << endl;
    /*****************************/
    //hash表年龄排序测试
    /*****************************/
    int ages[15] = {0,1,11,22,51,15,24,32,3,9,55,15,32,39,11};
    SortAges(ages,15);
    for(int i = 0;i < 15; i++)
    {
        cout << ages[i] <<',';
    }
    cout << endl;
    /*****************************/
    //旋转数组的最小数字测试
    /*****************************/
    int b[5] = {3,4,5,1,2};
    cout << Min(b,5) << endl;
    return 0;
}
