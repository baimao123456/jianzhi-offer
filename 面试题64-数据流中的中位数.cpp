/*************************************/
//数据流中的中位数
/*************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename T> class DynamicArray
{
public:
    void Insert(T num)
    {
        if(((min.size() + max.size()) & 1) == 0) //数据个数为偶数，num放进min中
        {
            //取出max中最大的元素放进min中
            //保证max中的所有元素小于min中元素
            if(max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());//max为最大堆

                num = max[0];          //取出max中的最大元素

                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        }
        else                            //数据的个数为奇数，num放进max中
        {
            //从min中取出最小的元素，放进max中
            if(min.size() >0 && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());//max为最大堆
        }
    }
    T GetMedian()
    {
        int size = min.size() + max.size();
        if(size == 0)
            return 0;

        T median = 0;
        if((size & 1) == 1) //如果是奇数
            median = min[0];
        else
            median = (max[0] + min[0]) / 2;

        return median;
    }
private:
    vector<T> min;
    vector<T> max;
};
int main(void)
{
    DynamicArray<double> d;
    d.Insert(1);
    d.Insert(2);
    d.Insert(3);
    d.Insert(4);
    d.Insert(5);
    cout << "the median num is :" << d.GetMedian() << endl;
    return 0;
}







