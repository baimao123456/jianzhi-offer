/************************/
//�������ظ�������
/************************/
#include <iostream>
#include <vector>
using namespace std;
bool duplicate(vector<int> data, int& duplication)
{
    int length = data.size();
    if(length <= 0)
        return false;

    for(int i = 0; i < length ;++i)    //��ֵ����������
    {
        if(data[i] < 0 || data[i] > length - 1)
            return false;
    }
    for(int i = 0; i < length ; ++i)
    {
        while(data[i] != i)         //һֱ��i���жϣ�ֱ����������
        {
            if(data[i] == data[data[i]]) //���iλ���ϴ�����ͬ��ֵ��˵���ظ���
            {
                duplication = data[i];
                return true;
            }
            swap(data[i], data[data[i]]);
        }
    }
    return false;
}
int main()
{
    int d;
    vector<int> number = {3,1,2,4,2,5,3};
    duplicate(number,d);
    cout << d << endl;
    return 0;
}
