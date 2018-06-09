
/*******************/
//面试题4，替换字符串中的空格
/*******************/
#include <iostream>

using namespace std;
//字符串测试
template<class T>
void showarr(T arr[],int length)
{
    for(int k = 0;k<length;k++)
        cout << arr[k] << ',';
    cout << endl;
}
void test1()
{
    char str1[] = "hello world";  //str1和str2是两个字符串数组，会分别分配空间
    char str2[] = "hello world";

    char* str3 = "hello world";    //当几个指针赋值给相同的常量字符串时，他们实际上会指向相同的内存地址
    char* str4 = "hello world";

    if(str1 == str2)
        cout << "str1 and str2 are same." << endl;
    else
        cout << "str1 and str2 are not same." << endl;
    if(str3 == str4)
        cout << "str3 and str4 are same." << endl;
    else
        cout << "str3 and str4 are not same." << endl;
}
/******************************************/
//相关题目测试，将两个有序数组合并到第一个数组内
/******************************************/
template<class T>
void Merge(T arr1[],T arr2[],int l1,int l2,int length1)
{
    int length = length1 - 1;
    int index1 = l1;
    int index2 = l1;
    while(index1 >= 0 && index2 >= 0)    //从后往前一次比较，将最大的数放到a1末尾，直到比较到第一个元素
        if(arr1[index1] > arr2[index2])      //将最大的放在后端
            arr1[length--] = arr1[index1--];
        else
            arr1[length--] = arr2[index2--];

    while(index1 >= 0)                   //将a1中剩余的元素依次放进去
        arr1[length--] = arr1[index1--];

    while(index2 >= 0)
        arr1[length--] = arr2[index2--];     //将a2中剩余的元素依次放进去
}
void test2()
{
    int a1[10] = {1,2,5,7,9};
    int a2[5] = {3,4,6,8,10};
    Merge(a1,a2,4,4,sizeof(a1)/sizeof(int));
    cout << "the length of a1 is :  " << (sizeof(a1)/sizeof(int)) << endl;
    showarr(a1,10);
}
/******************************************/
//替换空格,从前往后替换，字符移动比较多，时间复杂度O(n^2)
/******************************************/
template<class T>
void ReplaceBlack(T arr[],int length) //length为数组的总容量
{
    if(arr == NULL || length <= 0)    //如果数组为空，直接返回
        return;
    int i = 0;
    while(arr[i++] != '\0')           //从头判断空格，每判断出一个空格，就将空格之后的元素往后移动两个
    {
        if(arr[i] == ' ')             //进行替换
        {
            for(int j = length - 1;j > i;j--)
                arr[j + 2] = arr[j];
            arr[i++] = '%';
            arr[i++] = '2';
            arr[i++] = '0';
        }
        else
            continue;
    }
}
/******************************************/
//替换空格,从后往前替换，字符只需要移动一次,时间复杂度O(n)
/******************************************/
template<class T>
void ReplaceBlack2(T arr[],int length)  //length为数组的总容量
{
    if(arr == NULL || length <= 0)      //如果数组为空，直接返回
        return;
    int i = 0;
    int originalLength = 0;             //替换之前的长度
    int numberOfBlank = 0;              //空格的个数
    while(arr[i++] != '\0')             //查找空格的个数和字符串的长度
    {
        ++originalLength;
        if(arr[i] == ' ')
            ++numberOfBlank;
    }
    int newLength = originalLength + numberOfBlank*2; //newLength是把空格替换成'%20'之后的长度
    if(newLength > length)              //如果当前的数组的空间不能将全部的空格替换，则返回
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(arr[indexOfOriginal] == ' ') //如果遇见空格，则进行插入
        {
            arr[indexOfNew--] = '0';
            arr[indexOfNew--] = '2';
            arr[indexOfNew--] = '%';
        }
        else
            arr[indexOfNew--] = arr[indexOfOriginal];
        --indexOfOriginal;             //放置的位置很关键，不能放到上一行中的string[indexOfOriginal]，因为这是个条件不能每次都执行。
    }
    for(int k = 0;k<length;k++)        //输出替换空格之后的数组
        cout << arr[k];
    cout << endl;
}
int main()
{
    test1();
    char str1[18] = "we are happy.";
    //ReplaceBlack(str1,18);
    ReplaceBlack2(str1,sizeof(str1)/sizeof(char));
    test2();
    return 0;
}
