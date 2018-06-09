
/****************************/
//面试题22-栈的压入弹出序列
/****************************/
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
template<class T>
bool IsPopOrder(const T* pPush,const T* pPop,int nLength)
{
    bool bPossible = false;        //标志位
    if(pPush != NULL && pPop != NULL && nLength > 0) //如果ppush和ppop均不是0
    {
        const T* pNextPush = pPush;
        const T* pNextPop = pPop;

        stack<T>stackData;       //定义一个辅助栈，用来进行序列的压入弹出
        while(pNextPop - pPop < nLength)
        {
            while(stackData.empty() || stackData.top() != *pNextPop) //按ppop的栈顶元素来将ppush元素压入堆栈
            {
                if(pNextPush - pPush == nLength)   //如果pNextPush指向了最后一个元素，则退出循环
                    break;
                stackData.push(*(pNextPush++));    //将ppush元素压入栈
            }
            if(stackData.top() != *pNextPop)
                break;
            stackData.pop();
            pNextPop++;
        }
        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}
//利用vector作为参数的传递，代码简单
template<class T>
bool IsPopOrder2(vector<T> pPush,vector<T> pPop)
{
    if(pPush.size() == 0) return false;   //如果ppush为空，没有意义，返回false
    stack<T> stackData;                 //辅助栈，将ppush的元素压入栈，并按照ppop的顺序弹出栈
    for(int i = 0,j = 0;i < pPop.size();) //不停的将ppush的元素压入栈，直到栈顶元素和ppop的首元素相同
    {
        stackData.push(pPush[i++]);
        while(j < pPop.size() && stackData.top() == pPop[j]) //栈顶元素和ppop的首元素相同，弹出栈顶元素
        {
            stackData.pop();
            j++;   //！！！循环将栈中的元素按照ppop序列的顺序弹出栈
        }
    }
    return stackData.empty();  //如果最后栈为空，说明序列ppop是ppush的一个弹出序列，这个序列不唯一
}
int main()
{
    int push_list[] = {1,2,3,4,5};
    int pop_list[] = {4,3,5,1,2};

    vector<int> push_list2(push_list,push_list+5);
    vector<int> pop_list2(pop_list,pop_list+5);

    cout << IsPopOrder(push_list,pop_list,5) << endl;
    cout << IsPopOrder2(push_list2,pop_list2) << endl;
    return 0;
}
