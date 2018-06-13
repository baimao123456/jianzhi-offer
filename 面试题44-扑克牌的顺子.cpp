/*************************************/
//扑克牌的顺子
/*************************************/
#include <iostream>
#include <algorithm>
using namespace std;

//判断扑克牌是不是连续的
bool IsContinuous(vector<int> data)
{
    int length = data.size();        //扑克牌的张数
    int pai[14] = {0};               //用来记录每张牌的个数
    for(int i = 0; i < length; ++i)
    {
        pai[data[i]]++;
    }
    int numberOfZero = pai[0];       //0(大小王)的个数
    for(int j = 1;j < 14; ++j)
    {
        if(pai[j] == 1)              //如果不存在对子，则计算间隔的个数
        {
            for(int k = j; k < length - numberOfZero; k++)
                if((pai[k] == 0))    //遇见间隔就用 0 代替，所以这里 numberOfZero--
                    numberOfZero--;
            break;
        }
        else
            return false;
    }
    return (numberOfZero >= 0);

}
int main(void)
{
    vector<int> number = {1,2,3,4};
    cout << number.size() << endl;
    cout << IsContinuous(number);
    return 0;
}
