// 二阶构造初探
#include <stdio.h>

class TwoPhaseCons
{
private:
    TwoPhaseCons() {}                // 第一阶段构造函数
    bool construct() {return true;}  // 第二阶段构造函数

public:
    static TwoPhaseCons* NewInstance(); // 对象创建函数
};

TwoPhaseCons* TwoPhaseCons::NewInstance()
{
    TwoPhaseCons* ret = new TwoPhaseCons;

    // 若第二阶段构造失败，返回 NULL
    if( !(ret && ret->construct()) )
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}

int main()
{
    TwoPhaseCons *obj = TwoPhaseCons::NewInstance();

    printf("obj = %p\n", obj);

    delete obj;

    return 0;
}
/* 运行结果
obj = 027610C8
*/
