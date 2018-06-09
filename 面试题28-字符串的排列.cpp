/*******************************/
//字符串的排列
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
            swap(*pCh,*pBegin);           //求所有可能出现在第一个位置的字符，然后排列

            Permutation(pStr,pBegin + 1); //对pStr[pBegin + 1,end]进行全排列（划分成小问题）

            swap(*pCh,*pBegin);           //每次进行全排列后，字符串要恢复原来的状态
        }
    }
}
//对字符串进行全排列
void Permutation(char* pStr)
{
    if(pStr == NULL)
        return;
    Permutation(pStr,pStr);
}

//求字符串 str 的长度为 m 的字符组合
void Combination(char *str,int m,vector<char>& result)
{
    if(m == 0)                //如果没有可放的字符，则输出字符组合
    {
        vector<char>::iterator it = result.begin();
        for(;it < result.end();++it)
            cout << *it << ' ';
        cout << endl;
        return;
    }

    if(*str == '\0')          //如果到了字符串尾，同样返回
        return;

    result.push_back(*str);
    Combination(str + 1, m - 1, result); //把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符
    //cout << "not " << endl;

    result.pop_back();
    Combination(str + 1, m, result); //不把这个字符放到组合中去，则需要在剩下的n-1个字符中选取m个字符
    //cout << "yes " << endl;
}
//全组合
void Combination(char *str)
{
    int length = strlen(str);
    vector<char> result;
    for(i = 1;i <= length;i++)     //分别获取长度为 i 的组合
    {
        Combination(str,i,result);
    }
}*/
/****************************************/
//八皇后问题
/****************************************/
//构造的数组本来就是使所有皇后处于不同行不同列上，，所以这里仅需要判断是否在对角线上
//判断每一排列对应的八皇后是否在同一对角线上
bool check(int ColumnIndex[], int length)
{
    for(int i = 0;i < length; ++i)
    {
        for(int j = i + 1;j < length;++j)
        {
            if(abs(i - j) == abs(ColumnIndex[i] - ColumnIndex[j]))  //如果处于对角线上
                return false;
        }
    }
    return true;
}
//打印数组
void PrintArray(int ColumnIndex[], int length)
{
    for(int i = 0;i < length;i++)
        cout << ColumnIndex[i] << ' ';
    cout << endl;
}
int Qnum = 0;                     //用来记录摆放的种类个数
void Permutation(int ColumnIndex[], int index, int length)
{
    if(index == length)
    {
        if(check(ColumnIndex,length)) //检查是否满足条件
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
//八皇后问题解法，共有92种解法
void EightQueen(int NumOfQueen = 8)
{
    int ColumnIndex[NumOfQueen];      //初始化皇后放置的位置为不同行不同列
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
