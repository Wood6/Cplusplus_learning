// main.cpp 单类例模板
#include <iostream>
#include "singleton.h"

using namespace std;

class SObject
{
private:
    // 当前类需要使用单例模式
    // 可以先忽略下一行代码，直接去看main中的函数，然后再回来理解
    // 这里为什么要将Singleton<SObject>类声明为SObject类的友元类？
    // 其目的是为了让Singleton<SObject>类内部可以调用SObject的己被
    // 私有的构造函数
    friend class Singleton<SObject>;

    // 要单例的类，须将构造函数、拷贝构造函数和赋值操作符隐藏起来
    // 否则外界可以随便new
    SObject() {}
    SObject(const SObject& obj) {}
    SObject& operator = (const SObject& obj) {}

public:
    void print()
    {
        cout << "this = " << this << endl;
    }
};

int main()
{
    // Singleton<SObject>虽然是通过类模板产生的，但其实是一个实实在在
    // 存在的新的类，然后通过这个类，去创建SObject类的一个实例，由于
    // Singleton<SObject>类内部的GetInstance控制了SObject对象的实例
    // 的产生。因此，每个调用getInstance就只能获得SObject的一个对象。
    // 本质上，单例类模板是通过模板去创建一个类，然后利用这个类来控制另一个
    // 类对象的创建！
    SObject* pS1 = Singleton<SObject>::GetInstance();
    SObject* pS2 = Singleton<SObject>::GetInstance();
    SObject* pS3 = Singleton<SObject>::GetInstance();

    pS1->print();  // 打印出来的3个对象地址值一样，说明是单例
    pS2->print();
    pS3->print();
                   // 没有释放，单例设计就是存在于整个生命周期的,所以不释放
    return 0;
}
/* 运行结果
this = 0x26f10c8
this = 0x26f10c8
this = 0x26f10c8
*/
