/********************************
//���üӼ��˳����ӷ�
   1101      0110    10100   10000   11000
         --->     --->     --->   --->
   1011      10010   00100   01000   00000
********************************/
#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
    int sum, carry;         //��and��λ
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;
    }
    while(num2 != 0);            //ֱ����������λ

    return num1;
}
//��ʹ���µı�����������������ֵ
void swap_new(int& num1, int& num2)
{
    /*
    ���üӷ�
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    */
    //���� x��x�������Ϊ0���ص㣬����������������ֵ
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}
int main()
{
    cout << Add(-0,65536) << endl;
    int num1 = 2, num2 = 5;
    swap_new(num1, num2);
    cout << "after swap the two number is :" << num1 << ',' << num2 << endl;
    return 0;
}
