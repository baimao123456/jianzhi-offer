
/****************************/
//������22-ջ��ѹ�뵯������
/****************************/
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
template<class T>
bool IsPopOrder(const T* pPush,const T* pPop,int nLength)
{
    bool bPossible = false;        //��־λ
    if(pPush != NULL && pPop != NULL && nLength > 0) //���ppush��ppop������0
    {
        const T* pNextPush = pPush;
        const T* pNextPop = pPop;

        stack<T>stackData;       //����һ������ջ�������������е�ѹ�뵯��
        while(pNextPop - pPop < nLength)
        {
            while(stackData.empty() || stackData.top() != *pNextPop) //��ppop��ջ��Ԫ������ppushԪ��ѹ���ջ
            {
                if(pNextPush - pPush == nLength)   //���pNextPushָ�������һ��Ԫ�أ����˳�ѭ��
                    break;
                stackData.push(*(pNextPush++));    //��ppushԪ��ѹ��ջ
            }
            if(stackData.top() != *pNextPop)
                break;
            stackData.pop();
            pNextPop++;
        }
        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}
//����vector��Ϊ�����Ĵ��ݣ������
template<class T>
bool IsPopOrder2(vector<T> pPush,vector<T> pPop)
{
    if(pPush.size() == 0) return false;   //���ppushΪ�գ�û�����壬����false
    stack<T> stackData;                 //����ջ����ppush��Ԫ��ѹ��ջ��������ppop��˳�򵯳�ջ
    for(int i = 0,j = 0;i < pPop.size();) //��ͣ�Ľ�ppush��Ԫ��ѹ��ջ��ֱ��ջ��Ԫ�غ�ppop����Ԫ����ͬ
    {
        stackData.push(pPush[i++]);
        while(j < pPop.size() && stackData.top() == pPop[j]) //ջ��Ԫ�غ�ppop����Ԫ����ͬ������ջ��Ԫ��
        {
            stackData.pop();
            j++;   //������ѭ����ջ�е�Ԫ�ذ���ppop���е�˳�򵯳�ջ
        }
    }
    return stackData.empty();  //������ջΪ�գ�˵������ppop��ppush��һ���������У�������в�Ψһ
}
int main()
{
    int push_list[] = {1,2,3,4,5};
    int pop_list[] = {4,3,5,1,2};

    vector<int> push_list2(push_list,push_list+5);
    vector<int> pop_list2(pop_list,pop_list+5);

    cout << IsPopOrder(push_list,pop_list,5) << endl;
    cout << IsPopOrder2(push_list2,pop_list2) << endl;
    return 0;
}
