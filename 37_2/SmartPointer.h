// SmartPoint.h 智能指针类(仿STL中的auto_ptr)
#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

// 定义智能指针类
template <typename T>
class SmartPointer
{
private:
    // 用于保存要被管理对象的指针
    T* m_pointer;

public:
    SmartPointer(T* pointer = NULL) : m_pointer(pointer)
    {
    }

    SmartPointer(const SmartPointer<T>& obj)
    {
        // 当Pointer p2 = p1时，p1所指的堆空间由p2来接管
        // 即保证每次只能有一个智能指针指向同一堆空间
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    }

    SmartPointer<T>& operator = (const SmartPointer<T>& obj)
    {
        if(this != &obj)
        {
            delete m_pointer;
            m_pointer = obj.m_pointer;
            // 保证赋值操作时，只能由一个智能指针指向同一堆空间
            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
        }

        return *this;
    }

    // 重载->操作符，不能使用参数，所以也就只能定义一个重载函数
    T* operator -> ()
    {
        return m_pointer;
    }

    // 重载*操作符
    T& operator * ()
    {
        return *m_pointer;
    }

    bool isNull()
    {
        return (m_pointer == NULL);
    }

    // 返回对象的堆空间指针(仿auto_ptr智能指针)
    T* get()
    {
        return m_pointer;
    }

    ~SmartPointer()
    {
        // 智能指针被析构时，同时删除其所管理的T类的对象
        delete m_pointer;
    }
};

#endif
