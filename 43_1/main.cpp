// 组合关系示例
#include <iostream>

using namespace std;

// 内存类
class Memory
{
public:
    Memory() {cout << "Memory" << endl;}
    ~Memory() {cout << "~Memory" << endl;}
};

// 硬盘类
class Disk
{
public:
    Disk() {cout << "Disk" << endl;}
    ~Disk() {cout << "~Disk" << endl;}
};

// CPU类
class CPU
{
public:
    CPU() {cout << "CPU" << endl;}
    ~CPU() {cout << "~CPU" << endl;}
};

// 主板类
class MainBoard
{
public:
    MainBoard() {cout << "MainBoard" << endl;}
    ~MainBoard() {cout << "~MainBoard" << endl;}
};

// 电脑类
class Computer
{
private:
    // 组合关系：部分-整体关系（与Computer对象同生命期）
    Memory m_memory;
    Disk m_disk;
    CPU m_cpu;
    MainBoard m_mainboard;

public:
    Computer() {cout << "Computer" << endl;}
    ~Computer() {cout << "~Computer" << endl;}

    void power() {cout << "power()" << endl;}
    void reset() {cout << "reset()" << endl;}
};

int main()
{
    Computer c1; //先构造成员对象（按声明顺序），再调用类构造函数

    return 0;
}
/* 运行结果
Memory
Disk
CPU
MainBoard
Computer
~Computer
~MainBoard
~CPU
~Disk
~Memory
*/
