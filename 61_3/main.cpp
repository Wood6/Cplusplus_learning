// Qt中的智能指针类
#include<QPointer>
#include <QSharedPointer>
#include <qDebug>

class Test : public QObject
{
    QString m_name;
public:
    Test(const char* name)
    {
        m_name = name;
        qDebug() << "Hello, " << m_name << ".";
    }

    void print()
    {
        qDebug() << "I'm " << m_name <<".";
    }

    ~Test()
    {
        qDebug() << "Good bye, " << m_name <<".";
    }
};

int main()
{
    QPointer<Test> pt(new Test("SantaClaus"));// pt= new Test("SantaClaus")；
    QPointer<Test> pt1(pt);  // 所有权不会转让！与pt指向同一个堆空间
    QPointer<Test> pt2(pt);  // 所有权不会转让！与pt指向同一个堆空间

    pt->print();
    pt1->print();
    pt2->print();

    delete  pt;  //删除对象时，pt、pt1和pt2会同时被置空
    // 注意，pt本身是一个局部对象（而不是指针），但因QPointer<Test>实现了
    // operator Test*()这个类型转换函数(见第42课)，当delete pt时，由于delete
    // 要求后面跟一个指针，所以将隐式的把pt对象转为Test*指针类型。因此，删除
    // 的是pt所指的对象，而不是pt本身。


    qDebug() << "pt = "  << pt;
    qDebug() << "pt1 = " << pt1;
    qDebug() << "pt2 = " << pt2;

    qDebug() << endl;

    //带有引用计数
    QSharedPointer<Test> spt(new Test("Demo"));
    QSharedPointer<Test> spt1(spt);
    QSharedPointer<Test> spt2(spt);

    spt->print();
    spt1->print();
    spt2->print();

    return 0;
}

/* 运行结果
Hello,  "SantaClaus" .
I'm  "SantaClaus" .
I'm  "SantaClaus" .
I'm  "SantaClaus" .
Good bye,  "SantaClaus" .
pt =  QObject(0x0)
pt1 =  QObject(0x0)
pt2 =  QObject(0x0)


Hello,  "Demo" .
I'm  "Demo" .
I'm  "Demo" .
I'm  "Demo" .
Good bye,  "Demo" .
*/
