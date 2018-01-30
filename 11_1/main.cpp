// C方式中粗暴的类型转换
#include <stdio.h>

typedef void PF(int);

struct stPoint
{
    int x;
    int y;
};

int main()
{
    int v = 0x12345;

    PF *pf = (PF*)v;
    char c = char(v);  // 很古老的类型转换方法,很像函数调用
    stPoint *pSt = (stPoint*)v;

    pf(5);

    printf("pSt->x = %d\n", pSt->x);
    printf("pSt->y = %d\n", pSt->y);

    return 0;
}
/* QtCreator 运行结果
程序异常结束
*/
