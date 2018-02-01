// 类成员变量在不同存储空间上初始化的探索
#include <stdio.h>

class Test
{
private:
    int i;
    int j;

public:
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

    // 全局区静态存储区没有显示初始化，被初始化为0
    printf("gt.i = %d, gt.j = %d\n", gt.getI(), gt.getJ());
    // 栈上的对象没有显示初始化，初始化为随机值
    printf("st.i = %d, st.j = %d\n", st.getI(), st.getJ());
    // 堆上创建对象没有显示初始化，初始化为随机值
    printf("pt->i = %d, pt->j = %d\n", pt->getI(), pt->getJ());

    return 0;
}
/* 运行结果
gt.i = 0, gt.j = 0
st.i = 0, st.j = 80
pt->i = 8156752, pt->j = 8126660
*/
