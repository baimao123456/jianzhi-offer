/*******************************/
//��С��k����
/*******************************/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

//��ӡ����
void show(int *L,int length)
{
    for(int m = 0;m < length; m++) //��Ϊ�Ǵ�L[1]��ʼ�洢��û���Դ�L[1]��ʼ�����
        cout << L[m] << " ";
    cout << endl;
}

//��numbers[start]Ϊ���ޣ����������ҷֿ�
int Partition(int* numbers, int length, int start, int end)
{
    int pivotkey = numbers[start];      //ѡ���ָ����
    while(start < end)
    {
        while(start < end && numbers[end] >= pivotkey)    //�Ӻ���ǰ�ҵ���һ����pivotkeyС��ֵ
            end--;
        swap(numbers[start],numbers[end]);

        while(start < end && numbers[start] <= pivotkey)  //��ǰ�����ҵ���һ����pivotkey���ֵ
            start++;
        swap(numbers[start],numbers[end]);
    }

}
//����partition,�õ���С��k����,���Ӷ�ΪO(n)
void GetLeastNumbers(int* input, int n, int* output,int k)
{
    if(input == NULL || output == NULL || k > n || n <= 0 || k<= 0)
        return;

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while(index != k - 1)  //ѭ��ʹindex = k - 1����Ϊindex��0��ʼ������ʱindexǰ�ߵ�k������������С����
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
//����multiset�洢���֣�,�õ���С��k����,���Ӷ�ΪO(n*log(k))
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
            setIterator begin_set = leastNumbers.begin();  //��Ԫ�أ�set������Ԫ�أ�
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
