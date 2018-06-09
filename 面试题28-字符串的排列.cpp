/*******************************/
//�ַ���������
/*******************************/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int i = 0;
/*
void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
        printf("%s  %d\n",pStr,i++);
    else
    {
        for(char* pCh = pBegin; *pCh != '\0';++pCh)
        {
            swap(*pCh,*pBegin);           //�����п��ܳ����ڵ�һ��λ�õ��ַ���Ȼ������

            Permutation(pStr,pBegin + 1); //��pStr[pBegin + 1,end]����ȫ���У����ֳ�С���⣩

            swap(*pCh,*pBegin);           //ÿ�ν���ȫ���к��ַ���Ҫ�ָ�ԭ����״̬
        }
    }
}
//���ַ�������ȫ����
void Permutation(char* pStr)
{
    if(pStr == NULL)
        return;
    Permutation(pStr,pStr);
}

//���ַ��� str �ĳ���Ϊ m ���ַ����
void Combination(char *str,int m,vector<char>& result)
{
    if(m == 0)                //���û�пɷŵ��ַ���������ַ����
    {
        vector<char>::iterator it = result.begin();
        for(;it < result.end();++it)
            cout << *it << ' ';
        cout << endl;
        return;
    }

    if(*str == '\0')          //��������ַ���β��ͬ������
        return;

    result.push_back(*str);
    Combination(str + 1, m - 1, result); //������ַ��ŵ������ȥ��������������Ҫ��ʣ�µ�n-1���ַ���ѡȡm-1���ַ�
    //cout << "not " << endl;

    result.pop_back();
    Combination(str + 1, m, result); //��������ַ��ŵ������ȥ������Ҫ��ʣ�µ�n-1���ַ���ѡȡm���ַ�
    //cout << "yes " << endl;
}
//ȫ���
void Combination(char *str)
{
    int length = strlen(str);
    vector<char> result;
    for(i = 1;i <= length;i++)     //�ֱ��ȡ����Ϊ i �����
    {
        Combination(str,i,result);
    }
}*/
/****************************************/
//�˻ʺ�����
/****************************************/
//��������鱾������ʹ���лʺ��ڲ�ͬ�в�ͬ���ϣ��������������Ҫ�ж��Ƿ��ڶԽ�����
//�ж�ÿһ���ж�Ӧ�İ˻ʺ��Ƿ���ͬһ�Խ�����
bool check(int ColumnIndex[], int length)
{
    for(int i = 0;i < length; ++i)
    {
        for(int j = i + 1;j < length;++j)
        {
            if(abs(i - j) == abs(ColumnIndex[i] - ColumnIndex[j]))  //������ڶԽ�����
                return false;
        }
    }
    return true;
}
//��ӡ����
void PrintArray(int ColumnIndex[], int length)
{
    for(int i = 0;i < length;i++)
        cout << ColumnIndex[i] << ' ';
    cout << endl;
}
int Qnum = 0;                     //������¼�ڷŵ��������
void Permutation(int ColumnIndex[], int index, int length)
{
    if(index == length)
    {
        if(check(ColumnIndex,length)) //����Ƿ���������
        {
            ++Qnum;
            PrintArray(ColumnIndex,length);
        }
    }
    else
    {
        for(int i = index;i < length; i++)
        {
            swap(ColumnIndex[i],ColumnIndex[index]);
            Permutation(ColumnIndex,index + 1,length);
            swap(ColumnIndex[i],ColumnIndex[index]);
        }
    }

}
//�˻ʺ�����ⷨ������92�ֽⷨ
void EightQueen(int NumOfQueen = 8)
{
    int ColumnIndex[NumOfQueen];      //��ʼ���ʺ���õ�λ��Ϊ��ͬ�в�ͬ��
    for(int i = 0;i < NumOfQueen;i++)
        ColumnIndex[i] = i;
    Permutation(ColumnIndex,0,NumOfQueen);
}
int main()
{
    //cout << "hello world" << endl;
    //char c_list[] = "abcdef";
    //Permutation(c_list);
    //cout << c_list;
    //Combination(c_list);
    EightQueen();
    cout << Qnum;
    return 0;
}
