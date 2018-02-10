// 继承是代码复用的重要手段
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

// 惠普笔记本类继承电脑类，也就复用了Computer的代码
class HPBook : public Computer
{
private:
    string m_OS;

public:
    HPBook()
    {
        m_OS = "Windows10";  // 预装Windows10系统
    }

    void installOS(string os)
    {
        m_OS = os;
    }

    void showOS()
    {
        cout << m_OS << endl;
    }
};

// 惠普笔记本类继承电脑类，也就复用了Computer的代码
class MacBook : public Computer
{
public:
    void showOS()
    {
        cout << "Mac OS" << endl;
    }
};

int main()
{
    HPBook hp;

    hp.power();                 // 上电开机
    hp.showOS();
    hp.installOS("Windows7");   // 装Windows7系统
    hp.showOS();

    cout << endl;

    MacBook mac;
    mac.showOS();

    return 0;
}
/* 运行结果
Memory
Disk
CPU
MainBoard
Computer
power()
Windows10
Windows7

Memory
Disk
CPU
MainBoard
Computer
Mac OS
~Computer
~MainBoard
~CPU
~Disk
~Memory
~Computer
~MainBoard
~CPU
~Disk
~Memory
*/
