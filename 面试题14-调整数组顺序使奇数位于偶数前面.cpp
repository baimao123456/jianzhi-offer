/*******************************/
//调整数组使奇数位于偶数前面
/*******************************/
#include<iostream>
using namespace std;
//打印数组
template<class T>
void show(T* p,int length)
{
    for(int i = 0;i < length;i++)
        cout << p[i] << ' ';
    cout << endl;
}
//调整数组使奇数位于偶数前面
void ReorderOddEven(int * pData,unsigned int length)
{
    if(pData == NULL || length == 0)  //如果数组为空，直接返回
        return;
    int *pBegin = pData;               //头指针
    int *pEnd = pData + length - 1;    //尾指针
    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && (*pBegin & 0x1) != 0) //从头找偶数
            pBegin++;
        while(pBegin < pEnd && (*pEnd & 0x1) == 0)   //从后先前找奇数
            pEnd--;
        if(pBegin < pEnd)
        {
            swap(*pBegin,*pEnd);                     //交换两个值，使满足条件
        }
    }
}
//按照特定的要求来排序数组，func(int)为要求函数,传递的参数是int型，返回bool
void Reorder(int *pData,unsigned int length,bool(*func)(int))
{
    if(pData == NULL || length == 0)   //如果数组为空，直接返回
        return;

    int *pBegin = pData;               //头指针
    int *pEnd = pData + length - 1;    //尾指针
    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && !(func(*pBegin))) //从头找不符合func函数要求的元素
            pBegin++;

        while(pBegin < pEnd && (func(*pBegin)))   //从后先前找符合func函数要求的元素
            pEnd--;

        if(pBegin < pEnd)
        {
            swap(*pBegin,*pEnd);                  //交换两个值，使满足条件
        }
    }
}
//判断是否是奇数
bool isEven(int n)
{
    return (n & 1) == 0;
}
int main()
{
    cout << "Hello World" << endl;
    int a[] = {5,1,12,3,4,5,9,8,10};
    ReorderOddEven(a,9);
    show(a,9);
    Reorder(a,9,isEven);
    show(a,9);
    return 0;
}
