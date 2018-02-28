// 单例类示例
#include <iostream>

using namespace std;

class SObject
{
private:
    // 静态 c_instance ，用于保存实例对象的指针
    // 整个程序生命周期有效，自然就设置为static了
    static SObject* c_instance;

    // 隐藏构造函数，拷贝构造、赋值操作符
    SObject() {}
    SObject(const SObject& obj) {}
    SObject& operator = (const SObject& obj) {}

public:
    static SObject* GetInstance();

    void print()
    {
        cout << "this = " << this << endl;
    }
};

SObject* SObject::c_instance = NULL;

SObject* SObject::GetInstance()
{
    if( c_instance == NULL )
    {
        c_instance = new SObject;
    }

    return c_instance;
}

int main()
{
    SObject* pS1 = SObject::GetInstance();
    SObject* pS2 = SObject::GetInstance();
    SObject* pS3 = SObject::GetInstance();

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
