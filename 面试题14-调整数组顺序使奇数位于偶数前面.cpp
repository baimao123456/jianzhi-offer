/*******************************/
//��������ʹ����λ��ż��ǰ��
/*******************************/
#include<iostream>
using namespace std;
//��ӡ����
template<class T>
void show(T* p,int length)
{
    for(int i = 0;i < length;i++)
        cout << p[i] << ' ';
    cout << endl;
}
//��������ʹ����λ��ż��ǰ��
void ReorderOddEven(int * pData,unsigned int length)
{
    if(pData == NULL || length == 0)  //�������Ϊ�գ�ֱ�ӷ���
        return;
    int *pBegin = pData;               //ͷָ��
    int *pEnd = pData + length - 1;    //βָ��
    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && (*pBegin & 0x1) != 0) //��ͷ��ż��
            pBegin++;
        while(pBegin < pEnd && (*pEnd & 0x1) == 0)   //�Ӻ���ǰ������
            pEnd--;
        if(pBegin < pEnd)
        {
            swap(*pBegin,*pEnd);                     //��������ֵ��ʹ��������
        }
    }
}
//�����ض���Ҫ�����������飬func(int)ΪҪ����,���ݵĲ�����int�ͣ�����bool
void Reorder(int *pData,unsigned int length,bool(*func)(int))
{
    if(pData == NULL || length == 0)   //�������Ϊ�գ�ֱ�ӷ���
        return;

    int *pBegin = pData;               //ͷָ��
    int *pEnd = pData + length - 1;    //βָ��
    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && !(func(*pBegin))) //��ͷ�Ҳ�����func����Ҫ���Ԫ��
            pBegin++;

        while(pBegin < pEnd && (func(*pBegin)))   //�Ӻ���ǰ�ҷ���func����Ҫ���Ԫ��
            pEnd--;

        if(pBegin < pEnd)
        {
            swap(*pBegin,*pEnd);                  //��������ֵ��ʹ��������
        }
    }
}
//�ж��Ƿ�������
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
