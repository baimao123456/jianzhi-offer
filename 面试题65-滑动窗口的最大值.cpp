/*******************************/
//�������ڵ����ֵ
/*******************************/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxInWindows;         //�����������ڵ����ֵ
    if(num.size() >= size && size >= 1)
    {
        //����һ��˫�������������󴰿�ֵ�������е�λ��
        //����ֵ�ڶ��ף���С���ڶ�β(back)
        deque<int> index;

        //�ҵ���һ�����ڵ����ֵ
        for(unsigned int i = 0; i < size; ++i)
        {
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();    //���������Ǵ������ֵ��indexɾ��

            index.push_back(i);
        }

        for(unsigned int i = size; i < num.size(); ++i)
        {
            maxInWindows.push_back(num[index.front()]); //��ô������ֵ

            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();    //���������Ǵ������ֵ��indexɾ��
            //���index.front()�Ѿ����ڴ����У���Ҫ�Ӷ�����ɾ��
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
