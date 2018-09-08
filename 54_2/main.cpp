// 多继承问题2：钻石型继承产生冗余成员
#include <iostream>

using namespace std;

class People
{
protected:
    string m_name;
    int m_age;

public:
    People(string name, int age) : m_name(name), m_age(age) {}

    void print()
    {
        cout << "m_name = " << m_name << endl
             << "m_age = " << m_age << endl;
    }
};

// 中间类采用虚继承
class Teacher : virtual public People
{
public:
    Teacher(string name, int age) : People(name, age) {}
};

// 中间类采用虚继承
class Student : virtual public People
{
public:
    // 中间类虽然不关心顶层类的初始化，但是依旧得显示写出初始化操作
    Student(string name, int age) : People(name, age) {}
};

// 博士类(一个博士可能即是老师，又是学生)，采用直接继承
// 如果中间层的Teacher和Student不采用虚继承的话，那在Doctor
// 类中将有来自People类的mName、mAge等成员变量各两份，出现数据
// 冗余现象，而且在子类Doctor中，如果直接mName = 1，会出现二义性的错误
// 因为编译器不知道mName是来自Teacher类的还是Student类的
class Doctor : public Teacher, public Student
{
public:
    // 请注意，构造函数中的最后一个初始化People，也就是说采用虚继承的话，则
    // 最终的子类需调用顶层父类的构造函数，这也是虚继承的一大问题，因为在
    // 实际开发中，有时很难确定最顶层的基类
    Doctor(string name, int age) : Teacher(name, age),
        Student(name, age), People(name, age) {}
};

int main()
{
    Doctor d("Wood", 25);

    d.print();

    return 0;
}
/* 运行结果
m_name = Wood
m_age = 25
*/
