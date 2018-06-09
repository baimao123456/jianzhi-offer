/**********************************/
//第一次只出现一次的字符
/**********************************/
#include <iostream>
using namespace std;
char FirstNotRepeatingChar(string str)
{
    if(str.size() <= 0)
        return '\0';
    const int tableSize = 256;
    unsigned int hashTable[tableSize] = {0};

    for(int i = 0; i < str.size(); i++)
    {
        hashTable[str[i]]++;
    }
    for(int i = 0; i < str.size(); i++)
    {
        if(hashTable[str[i]] == 1)
            return str[i];
    }
    return '\0';
}
int main()
{
    string str = "helho world";
    cout << str << endl;
    cout << "the first char that occur only once is :  ";
    cout << FirstNotRepeatingChar(str);
}
