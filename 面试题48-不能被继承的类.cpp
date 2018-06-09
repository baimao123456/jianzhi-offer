/********************************
//���ܱ��̳е���
********************************/
#include <iostream>
using namespace std;
//��һ�ַ����������캯����Ϊ˽��
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
//������Ԫ�ܹ��������˽�г�Ա�ص�
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
    SealedClass2 s;   //�ܱ�ʵ����
    Try t;
    return 0;
}
