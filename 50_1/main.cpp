// �������ڴ沼��ʵ�ʾ���һ��struct
#include <iostream>

using namespace std;

class classTest
{
private:
    int i;
    int j;
    char c;
    double d;

public:
    void print()
    {
        cout << "i = " << i << endl
             << "j = " << j << endl
             << "c = " << c << endl
             << "d = " << d << endl;
    }
};

struct stTest
{
    int i;
    int j;
    char c;
    double d;
};

int main()
{
    classTest t1;

    // class �� struct ���ڴ沼������һ���ġ���С��ͬ
    cout << "sizeof(classTest) = " << sizeof(classTest) << endl; // 24
    cout << "sizeof(t1) = " << sizeof(t1) << endl;               // 24
    cout << "sizeof(stTest) = " << sizeof(stTest) << endl;       // 24

    t1.print();

    cout << endl;

    stTest* pst = reinterpret_cast<stTest*>(&t1); // ����ǿ��ת���ṹ��

    // ���ýṹ������ private ��Ա���и�ֵ(ע���� private ��Ա)
    // ˵�� class ������ʱ,private ����Ȩ��ֻ�ڱ����������á�
    pst->i = 1;
    pst->j = 2;
    pst->c = 'c';
    pst->d = 3.1415;

    t1.print();        // class �е� private ��Ա���ı�

    return 0;
}
/* ���н��  Windows��QtCreator��������н��
sizeof(classTest) = 24
sizeof(t1) = 24
sizeof(stTest) = 24
i = 4200656
j = 65535
c =
d = 1.23077e-312

i = 1
j = 2
c = c
d = 3.1415

  ** linux ��g++��������н�� **
sizeof(classTest) = 20
sizeof(t1) = 20
sizeof(stTest) = 20
i = -1219271507
j = -1217731644
c =
d = -9.64093e-42

i = 1
j = 2
c = c
d = 3.1415
*/

