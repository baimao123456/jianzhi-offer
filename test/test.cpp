#include <iostream>
using namespace std;

int main()
{
    int a;
    int num[10]={0};
    while(cin >> a)
    {
        for(int i = 0; a > 0; i++)
        {
            str[i] = a%10;
            a /= 10;
        }
        for(int i = 0; i < str.size(); i++)
            cout << str[i];
    }
}
