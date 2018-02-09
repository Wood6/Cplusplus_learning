// 智能指针类
#include <iostream>

using namespace std;

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i)
    {
        cout << "Test::Test(int i = 0)" << endl;
    }

    int getValue() {return m_i;}
};

// 定义智能指针类
class SmartPointer
{
private:
    // 用于保存要被管理对象的指针
    Test* m_pointer;   // 学习模板技术后这里就可以不特指Test类了

public:
    SmartPointer(Test* pointer = NULL) : m_pointer(pointer)
    {
        cout << "SmartPointer::SmartPointer(Test* pointer = NULL)" << endl;
    }

    SmartPointer(const SmartPointer& obj)
    {
        // 当Pointer p2 = p1时，p1所指的堆空间由p2来接管
        // 即保证每次只能有一个智能指针指向同一堆空间
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer&>(obj).m_pointer = NULL;
        cout << "SmartPointer::SmartPointer(const SmartPointer& obj)" << endl;
    }

    SmartPointer& operator = (const SmartPointer& obj)
    {
        cout << "SmartPointer::SmartPointer& operator = (const SmartPointer& obj)" << endl;
        if(this != &obj)
        {
            delete m_pointer;
            m_pointer = obj.m_pointer;
            // 保证赋值操作时，只能由一个智能指针指向同一堆空间
            const_cast<SmartPointer&>(obj).m_pointer = NULL;
        }

        return *this;
    }

    // 重载->操作符，不能使用参数，所以也就只能定义一个重载函数
    Test* operator -> ()
    {
        return m_pointer;
    }

    // 重载*操作符
    // friend Test& operator * (const SmartPointer& obj);
    Test& operator * ()
    {
        return *m_pointer;
    }

    bool isNull()
    {
        return (m_pointer == NULL);
    }

    ~SmartPointer()
    {
        // 智能指针被析构时，同时删除其所管理的Test类的对象
        delete m_pointer;
        cout << "SmartPointer::~SmartPointer(), m_pointer = " << m_pointer << endl;
    }
};

// 这里有个奇怪的问题， ->确实不能重载为全局函数
// 但是* 重载为全局函数没有报错，不过专门写个指向int型数据的类
// 发现运行结果异常
/*
Test& operator * (const SmartPointer& obj)
{
    return *(obj.m_pointer);
}
*/


int main()
{
    // 这里是在构造p1对象，现代编译器这句本质就相当于
    // SmartPointer p1(new Test(5))，这个就会调用构造函数,new Test(5)
    // 返回的地址值就是构造函数SmartPointer(Test* pointer = NULL)的参数
    // 这样自然就构造了p1这个对象了
    SmartPointer p1 = new Test(5);

    cout << "----------------------" << endl;
    SmartPointer p3(new Test(5));
    cout << "----------------------" << endl;

    cout << p1->getValue() << endl;
    //cout << "p1.m_pointer = " << p1-> << endl;   // error
    cout << "p1.m_pointer = " << p1.operator -> () << endl;

    // p2接管了p1所指的堆空间，保证每次只能由一个智能指针指向堆空间
    SmartPointer p2 = p1;
    cout << "p1.m_pointer = " << p1.operator -> () << endl;
    cout << "p2.m_pointer = " << p2.operator -> () << endl;

    // p1指向NULL了，不再指向原来的堆空间
    // p2接管了p1所指堆空间
    cout << p1.isNull() << endl;
    cout << p2.isNull() << endl;

    cout << p2->getValue() << endl;

    // p2++;不重载++，因为每次只能一个智能指针指向堆空间，这种++操作没意义
    // p2智能指针生命期结束，会自动释放接管的堆空间

    return 0;
}
/* 运行结果
Test::Test(int i = 0)                             // 优化后省去临时对象的过程
SmartPointer::SmartPointer(Test* pointer = NULL)  // 等价于SmartPointer p1(new Test(5))
----------------------
Test::Test(int i = 0)
SmartPointer::SmartPointer(Test* pointer = NULL)
----------------------
5
p1.m_pointer = 0x2f210c8
SmartPointer::SmartPointer(const SmartPointer& obj)
p1.m_pointer = 0
p2.m_pointer = 0x2f210c8
1
0
5
SmartPointer::~SmartPointer(), m_pointer = 0x2f210c8
SmartPointer::~SmartPointer(), m_pointer = 0x2f210d8
SmartPointer::~SmartPointer(), m_pointer = 0

** .pro中 加上QMAKE_CXXFLAGS += -fno-elide-constructors
** 关闭编译器优化后的编译运行结果
Test::Test(int i = 0)
SmartPointer::SmartPointer(Test* pointer = NULL)    // 生成了个临时对象
SmartPointer::SmartPointer(const SmartPointer& obj) // 将临时对象拷贝构造给p1
SmartPointer::~SmartPointer(), m_pointer = 0        // 析构掉临时对象
----------------------
Test::Test(int i = 0)
SmartPointer::SmartPointer(Test* pointer = NULL)
----------------------
5
p1.m_pointer = 0x2e510c8
SmartPointer::SmartPointer(const SmartPointer& obj)
p1.m_pointer = 0
p2.m_pointer = 0x2e510c8
1
0
5
SmartPointer::~SmartPointer(), m_pointer = 0x2e510c8
SmartPointer::~SmartPointer(), m_pointer = 0x2e510d8
SmartPointer::~SmartPointer(), m_pointer = 0
*/
