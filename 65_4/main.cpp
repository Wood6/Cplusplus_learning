// 在构造函数中捕获异常、做善后处理后重新抛出异常
#include <iostream>

using namespace std;

class Test
{
private:
    int* p1;
    int* p2;

public:
    Test()
    {
        int nStep = 0;
        cout<< "Test()" << endl;
        try
        {
            nStep = 1;
            p1 = new int[5];

            if( p1 == NULL)
            {
                //delete[] p1;
                throw nStep; // 制造异常
            }

            nStep = 2;
            p2 = new int[10];

            if( p2 == NULL )
            {
                //delete p2;
                throw nStep; // 制造异常
            }
        }
        catch(int n)
        {
            //构造函数中发生异常时，析构函数不会被调用，所以
            //要自己做善后处理！
            if(n>=1)
               delete[] p1;  // 第1步出错时，销毁p1堆空间

            if(n>=2)
               delete[] p2;  // 第2步出错时，销毁p2\p1堆空间

            throw n; // 继续抛出，通知调用者构造函数调用失败
        }
    }

    ~Test()
    {
        cout <<"~Test()" << endl;
        delete[] p1;
        delete[] p2;
    }
};

int main()
{
    try
    {
        Test t;  // Test的构造函数中可能发生异常

        // 上述处理方式，实际当异常发生时。析构函数依旧是没有调用的
        // 只是此事构造函数做了善后处理，做了析构函数的事情，会释放
        // 掉申请的堆内存，因此不会造成内存泄漏
    }
    catch (int e)
    {
        cout << "Catch:" << e << endl;
    }

    return 0;
}
/* 运行结果
Test()
~Test()
*/
