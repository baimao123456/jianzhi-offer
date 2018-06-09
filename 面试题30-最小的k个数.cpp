/*******************************/
//最小的k个数
/*******************************/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

//打印数组
void show(int *L,int length)
{
    for(int m = 0;m < length; m++) //因为是从L[1]开始存储的没所以从L[1]开始输出；
        cout << L[m] << " ";
    cout << endl;
}

//以numbers[start]为界限，将数组左右分开
int Partition(int* numbers, int length, int start, int end)
{
    int pivotkey = numbers[start];      //选定分割的数
    while(start < end)
    {
        while(start < end && numbers[end] >= pivotkey)    //从后往前找到第一个比pivotkey小的值
            end--;
        swap(numbers[start],numbers[end]);

        while(start < end && numbers[start] <= pivotkey)  //从前往后找到第一个比pivotkey大的值
            start++;
        swap(numbers[start],numbers[end]);
    }

}
//利用partition,得到最小的k个数,复杂度为O(n)
void GetLeastNumbers(int* input, int n, int* output,int k)
{
    if(input == NULL || output == NULL || k > n || n <= 0 || k<= 0)
        return;

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while(index != k - 1)  //循环使index = k - 1（因为index从0开始），此时index前边的k个数，就是最小的数
    {
        if(index > k - 1)
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        if(index < k - 1)
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }
    for(int i = 0;i < k;++i)
        output[i] = input[i];
}
//利用multiset存储数字，,得到最小的k个数,复杂度为O(n*log(k))
typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;
void GetLeastNumbers2(vector<int>& data,intSet& leastNumbers, int k)
{
    leastNumbers.clear();
    if(k < 1 || data.size() < k)
        return;

    vector<int>::const_iterator iter = data.begin();
    for(; iter != data.end(); ++iter)
    {
        if(leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else
        {
            setIterator begin_set = leastNumbers.begin();  //首元素（set中最大的元素）
            if(*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(begin_set);
                leastNumbers.insert(*iter);
            }
        }
    }
}
int main()
{
    int input[] = {1,3,9,4,0,2,2,3,4,9,8};
    int output[5]={0};

    cout << "the k least number is :" << endl;
    GetLeastNumbers(input, 11, output, 5);
    show(output, 5);

    vector<int> input_vector(input,input + 11);
    intSet outset;
    cout << "the k least number is :" << endl;
    GetLeastNumbers2(input_vector,outset,5);

    setIterator iter = outset.end();
    do
    {
        --iter;
        cout << *iter << ' ';
    }while(iter != outset.begin());

    return 0;
}
