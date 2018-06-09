/**********************************/
//二进制中1的个数
/**********************************/
#include <iostream>
using namespace std;
//二进制中1的个数,循环次数为n，比如n是int类型，则需要循环32次
int NumberOf1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}
//比较巧妙的求1的个数
int NumberOf1_Best(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n = (n -1) & n;  //n-1会让最右边的1的右边的0变成1，原来的1变成0
        //此时的n中含有的1的个数会减少，直到n=0
    }
    return count;
}
int main()
{
    cout << "hello world" << endl;
    cout << NumberOf1(-100) << endl;
    cout << NumberOf1_Best(-100) << endl;
    return 0;
}
