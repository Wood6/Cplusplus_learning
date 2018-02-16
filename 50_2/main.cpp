// C++示例结果为后面用C实现作比对
#include <iostream>

using namespace std;

class Test
{
private:
    int m_i;
    int m_j;

public:
    Test(int i, int j) : m_i(i), m_j(j) {}

    getMi() {return m_i;}
    getMj() {return m_j;}

    int add(int v)
    {
        return m_i + m_j + v;
    }
};

int main()
{
    Test t1(1, 2);

    cout << "sizeof(t1) = " << sizeof(t1) << endl;
    cout << "m_i = " << t1.getMi() << endl;
    cout << "m_j = " << t1.getMj() << endl;
    cout << "t1.add(3) = " << t1.add(3) << endl;

    return 0;
}
/* 运行结果
sizeof(t1) = 8
m_i = 1
m_j = 2
t1.add(3) = 6
*/
