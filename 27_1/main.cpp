// 构造函数没有预期构造会怎样？
#include <stdio.h>

class Test
{
private:
    int m_length;
    int *m_p;
    bool m_status;

public:
    Test(int len) : m_status(false)
    {
        m_length = len;

        return;    // return，会导致构造函数立即返回

        m_p = new int[len];

        m_status = true;
    }

    ~Test() {delete m_p;}

    int gerLen() {return m_length;}
    bool getStatus() {return m_status;}

    bool setValue(int index, int v)
    {
        bool bRet = (0 <= index) && (index < m_length);

        if( bRet )
        {
            m_p[index] = v;
        }

        return bRet;
    }

    bool getValue(int index, int& v)
    {
        bool bRet = (0 <= index) && (index < m_length);

        if( bRet )
        {
            v = m_p[index];
        }

        return bRet;
    }

};

int main()
{
    Test array = 5;

    // 从类的使用者角度看，完全不知道构造没有完成
    // 到这里就以为成功创建了5个元素的数组类，然后
    // 就去使用，但却触发段错误
    // 原因就是：构造没有按照预期的完成

    for(int i=0; i<array.gerLen(); i++)
    {
        array.setValue(i, i);
    }

    return 0;
}
/* 运行结果 Windows环境下QtCreator编译运行结果
程序异常结束

 ** linux 中编译运行结果 **
Segmentation fault (core dumped)
*/
