/*************************************/
//�������е���λ��
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
        if(((min.size() + max.size()) & 1) == 0) //���ݸ���Ϊż����num�Ž�min��
        {
            //ȡ��max������Ԫ�طŽ�min��
            //��֤max�е�����Ԫ��С��min��Ԫ��
            if(max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());//maxΪ����

                num = max[0];          //ȡ��max�е����Ԫ��

                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        }
        else                            //���ݵĸ���Ϊ������num�Ž�max��
        {
            //��min��ȡ����С��Ԫ�أ��Ž�max��
            if(min.size() >0 && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());//maxΪ����
        }
    }
    T GetMedian()
    {
        int size = min.size() + max.size();
        if(size == 0)
            return 0;

        T median = 0;
        if((size & 1) == 1) //���������
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







