// 类的成员函数指针
#include <iostream>

using namespace std;

class Test
{
public:
    void show()
    {
        cout << "Test::show()" << endl;
    }
};

void func()
{
    printf("func()\n");
}

//声明类成员函数指针
typedef void (Test::* pClassFunc)();
typedef void (*pFunc)();

int main()
{
    Test t;

    //pClassFunc pClassF = t.show();   // 错误,函数名就是函数地址
    pClassFunc pClassF = t.show;       // &(t.show) 也是一样的

    t.show();
    (t.*pClassF)();        // Test::show()

    //pFunc pf = func()    // 错误
    pFunc pf = func;       // pFunc pf = &func; 这个也可以
    pf();
    (*pf)();

    return 0;
}
/* 运行结果
Test::show()
Test::show()
func()
func()
*/
