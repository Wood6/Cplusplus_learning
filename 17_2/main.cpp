// 构造函数初探
#include <stdio.h>

class Test
{
private:
    int i;
    int j;

public:
    Test()
    {
        printf("Test() begin\n");
        i = 100;
        j = 200;
        printf("Test() end\n");
    }

    int getI()
    {
        return i;
    }

    int getJ()
    {
        return j;
    }
};

Test gt;                     // 全局对象

int main()
{
    Test st;                 // 栈
    Test *pt = new Test;     // 堆

    printf("gt.i = %d, gt.j = %d\n", gt.getI(), gt.getJ());
    printf("st.i = %d, st.j = %d\n", st.getI(), st.getJ());
    printf("pt->i = %d, pt->j = %d\n", pt->getI(), pt->getJ());

    return 0;
}
/* 运行结果
Test() begin
Test() end
Test() begin
Test() end
Test() begin
Test() end
gt.i = 100, gt.j = 200
st.i = 100, st.j = 200
pt->i = 100, pt->j = 200
*/
