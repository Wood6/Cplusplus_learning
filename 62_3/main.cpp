// main.cpp
#include<iostream>
#include "Singleton.h"

using namespace std;

class Test
{
private:
    //构造函数私有化
    Test(){}
    Test(const Test&);
    Test& operator=(const Test&);

    friend class singleton_default<Test>;

public:
    void print()
    {
        cout << "test::this " << this <<endl;
    }
};

int main()
{
    Test& t= INSTANCE(Test);
    t.print();

    Test& t2=INSTANCE(Test);
    t2.print();
    return 0;
}
/* 运行结果
test::this 0x403044
test::this 0x403044
*/
