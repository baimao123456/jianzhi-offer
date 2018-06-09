
/*******************/
//������4���滻�ַ����еĿո�
/*******************/
#include <iostream>

using namespace std;
//�ַ�������
template<class T>
void showarr(T arr[],int length)
{
    for(int k = 0;k<length;k++)
        cout << arr[k] << ',';
    cout << endl;
}
void test1()
{
    char str1[] = "hello world";  //str1��str2�������ַ������飬��ֱ����ռ�
    char str2[] = "hello world";

    char* str3 = "hello world";    //������ָ�븳ֵ����ͬ�ĳ����ַ���ʱ������ʵ���ϻ�ָ����ͬ���ڴ��ַ
    char* str4 = "hello world";

    if(str1 == str2)
        cout << "str1 and str2 are same." << endl;
    else
        cout << "str1 and str2 are not same." << endl;
    if(str3 == str4)
        cout << "str3 and str4 are same." << endl;
    else
        cout << "str3 and str4 are not same." << endl;
}
/******************************************/
//�����Ŀ���ԣ���������������ϲ�����һ��������
/******************************************/
template<class T>
void Merge(T arr1[],T arr2[],int l1,int l2,int length1)
{
    int length = length1 - 1;
    int index1 = l1;
    int index2 = l1;
    while(index1 >= 0 && index2 >= 0)    //�Ӻ���ǰһ�αȽϣ����������ŵ�a1ĩβ��ֱ���Ƚϵ���һ��Ԫ��
        if(arr1[index1] > arr2[index2])      //�����ķ��ں��
            arr1[length--] = arr1[index1--];
        else
            arr1[length--] = arr2[index2--];

    while(index1 >= 0)                   //��a1��ʣ���Ԫ�����ηŽ�ȥ
        arr1[length--] = arr1[index1--];

    while(index2 >= 0)
        arr1[length--] = arr2[index2--];     //��a2��ʣ���Ԫ�����ηŽ�ȥ
}
void test2()
{
    int a1[10] = {1,2,5,7,9};
    int a2[5] = {3,4,6,8,10};
    Merge(a1,a2,4,4,sizeof(a1)/sizeof(int));
    cout << "the length of a1 is :  " << (sizeof(a1)/sizeof(int)) << endl;
    showarr(a1,10);
}
/******************************************/
//�滻�ո�,��ǰ�����滻���ַ��ƶ��Ƚ϶࣬ʱ�临�Ӷ�O(n^2)
/******************************************/
template<class T>
void ReplaceBlack(T arr[],int length) //lengthΪ�����������
{
    if(arr == NULL || length <= 0)    //�������Ϊ�գ�ֱ�ӷ���
        return;
    int i = 0;
    while(arr[i++] != '\0')           //��ͷ�жϿո�ÿ�жϳ�һ���ո񣬾ͽ��ո�֮���Ԫ�������ƶ�����
    {
        if(arr[i] == ' ')             //�����滻
        {
            for(int j = length - 1;j > i;j--)
                arr[j + 2] = arr[j];
            arr[i++] = '%';
            arr[i++] = '2';
            arr[i++] = '0';
        }
        else
            continue;
    }
}
/******************************************/
//�滻�ո�,�Ӻ���ǰ�滻���ַ�ֻ��Ҫ�ƶ�һ��,ʱ�临�Ӷ�O(n)
/******************************************/
template<class T>
void ReplaceBlack2(T arr[],int length)  //lengthΪ�����������
{
    if(arr == NULL || length <= 0)      //�������Ϊ�գ�ֱ�ӷ���
        return;
    int i = 0;
    int originalLength = 0;             //�滻֮ǰ�ĳ���
    int numberOfBlank = 0;              //�ո�ĸ���
    while(arr[i++] != '\0')             //���ҿո�ĸ������ַ����ĳ���
    {
        ++originalLength;
        if(arr[i] == ' ')
            ++numberOfBlank;
    }
    int newLength = originalLength + numberOfBlank*2; //newLength�ǰѿո��滻��'%20'֮��ĳ���
    if(newLength > length)              //�����ǰ������Ŀռ䲻�ܽ�ȫ���Ŀո��滻���򷵻�
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(arr[indexOfOriginal] == ' ') //��������ո�����в���
        {
            arr[indexOfNew--] = '0';
            arr[indexOfNew--] = '2';
            arr[indexOfNew--] = '%';
        }
        else
            arr[indexOfNew--] = arr[indexOfOriginal];
        --indexOfOriginal;             //���õ�λ�úܹؼ������ܷŵ���һ���е�string[indexOfOriginal]����Ϊ���Ǹ���������ÿ�ζ�ִ�С�
    }
    for(int k = 0;k<length;k++)        //����滻�ո�֮�������
        cout << arr[k];
    cout << endl;
}
int main()
{
    test1();
    char str1[18] = "we are happy.";
    //ReplaceBlack(str1,18);
    ReplaceBlack2(str1,sizeof(str1)/sizeof(char));
    test2();
    return 0;
}
