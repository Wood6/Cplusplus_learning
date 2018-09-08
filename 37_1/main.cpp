// 示例内存泄漏
#include <iostream>

using namespace std;

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i)
    {
        cout << "Test::Test(int i = 0), i = " << i << endl;
    }

    ~Test()
    {
        cout << "Test::~Test()" << endl;
    }
};

int main()
{
    for(int i=0; i<5; i++)
    {
        Test* p = new Test(i);
    }

    // 有在堆空间上构造对象，却没有释放对象，这就造成了内存泄漏

    return 0;
}
/* 运行结果
Test::Test(int i = 0), i = 0
Test::Test(int i = 0), i = 1
Test::Test(int i = 0), i = 2
Test::Test(int i = 0), i = 3
Test::Test(int i = 0), i = 4
*/
