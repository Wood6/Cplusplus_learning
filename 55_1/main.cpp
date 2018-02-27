// new/delete 和 malloc/free 的区别
#include <iostream>

// for malloc\free函数。同时说明这两者都是函数，而不是关键字！
// Windows下QtCreator没有这个也可以，在linux的g++下没有这个报错
#include <cstdlib>

using namespace std;

class Test
{
private:
    int* m_p;

public:
    Test()
    {
        cout << "Test::Test()" << endl;
        m_p = new int(22);
        cout << "*m_p = " << *m_p << endl;
    }

    ~Test()
    {
        delete m_p;
        cout << "Test::~Test()" << endl;
    }
};

int main()
{
    // 申请堆空间->在堆空间上调用构造函数初始化
    Test* pn = new Test;

    // 只会申请堆空间,不初始化因为没有构造函数的调用
    Test* pm = (Test*)malloc(sizeof(Test));

    // 调用析构函数：先将堆空间上内容(对象中的成员指针)释放掉->归还对象所占的堆
    // 空间。如果这里混用free(pn)，则会造成内存泄漏（只归还pn指向的对象所占的
    // 对空间，但没有对对象中的成员指针进行释放）！
    delete pn;

    // 如果这里误用delete来释放pm所指的空间时，会同时调用
    // 析构函数，但因m_p指针所指空间是未知，出现误删除的bug。
    free(pm);

    return 0;
}
/* 运行结果
Test::Test()
*m_p = 22
Test::~Test()
*/
