// 命名空间的使用
#include <stdio.h>

namespace First
{
    int i =1;
}

namespace Second
{
    int i = 2;

    // 命名空间的嵌套
    namespace Internal
    {
        struct st
        {
            int x;
            int y;
        };
    }
}

int main()
{
    using namespace First;// 使用First整个命名空间
    using Second::Internal::st;// 使用命名空内部的st结构体

    printf("First::i = %d\n", i);          // 可以直接写i，因为使用了First整个命名空间
    printf("Second::i = %d\n", Second::i); // 须带命名空间的名字

    st s = {2, 3};                         // 也可以 Second::Internal::st s = {2, 3};
    printf("Second::Internal::st.x = %d\n", s.x);
    printf("Second::Internal::st.y = %d\n", s.y);

    return 0;
}
/* 运行结果
First::i = 1
Second::i = 1
Second::Internal::st.x = 2
Second::Internal::st.y = 3
*/
