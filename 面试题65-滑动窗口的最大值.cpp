/*******************************/
//滑动窗口的最大值
/*******************************/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxInWindows;         //用来滑动窗口的最大值
    if(num.size() >= size && size >= 1)
    {
        //定义一个双向队列来保存最大窗口值在数组中的位置
        //最大的值在队首，较小的在队尾(back)
        deque<int> index;

        //找到第一个窗口的最大值
        for(unsigned int i = 0; i < size; ++i)
        {
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();    //将不可能是窗口最大值的index删除

            index.push_back(i);
        }

        for(unsigned int i = size; i < num.size(); ++i)
        {
            maxInWindows.push_back(num[index.front()]); //获得窗口最大值

            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();    //将不可能是窗口最大值的index删除
            //如果index.front()已经不在窗口中，需要从队列中删除
            if(!index.empty() && index.front() <= (int)(i - size))
                index.pop_front();

            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }
    return maxInWindows;
}
int main()
{
    vector<int> num = {2,3,4,2,6,2,5,1};
    vector<int> MaxWindows = maxInWindows(num, 3);

    for(int i =0; i < MaxWindows.size(); ++i)
        cout << MaxWindows[i] << ',';
    cout << endl;

    return 0;
}
