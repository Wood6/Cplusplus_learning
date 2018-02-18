// 接口类
#include <iostream>

using namespace std;

// 接口类：没有成员变量，所有成员函数都是虚函数
class Channel
{
public:
    virtual bool open() = 0;
    virtual void close() = 0;
    virtual bool send(char* buf, int len) = 0;
    virtual int receive(char* buf, int len) = 0;
};

int main()
{
    return 0;
}
