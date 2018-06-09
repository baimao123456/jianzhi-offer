/********************************
//不能被继承的类
********************************/
#include <iostream>
using namespace std;
//第一种方法，将构造函数设为私有
class SealedClass1
{
public:
    static SealedClass1* GetInstance()
    {
        return new SealedClass1();
    }
    static void DeleteInstance(SealedClass1* pInstance)
    {
        delete pInstance;
    }
private:
    SealedClass1() {}
    ~SealedClass1() {}
};
//利用友元能够访问类的私有成员特点
template <typename T> class MakeSealed
{
    friend T;

private:
    MakeSealed() {}
    ~MakeSealed() {}
};
class SealedClass2 : virtual public MakeSealed<SealedClass2>
{
public:
    SealedClass2() {}
    ~SealedClass2() {}
};
class Try : public SealedClass2
{
public:
    Try();
    ~Try();
};
int main()
{
    //SealedClass1 s = new SealedClass1();
    SealedClass2 s;   //能被实例化
    Try t;
    return 0;
}
