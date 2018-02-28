// SmartPointer.h 智能指针类(仿STL中的shared_ptr)
#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

// 引用计数类
class SmartCount
{
private:
    int useCount;  // 计数变量

public:
    SmartCount(int c) : useCount(c) {}
    ~SmartCount() {}

    // 增加引用计数
    int addRef()
    {
        return ++useCount;
    }

    // 减少引用计数
    int release()
    {
        return --useCount;
    }

    // 获取当前引用计数
    int getCount()
    {
        return useCount;
    }
};

// 具有引用计数功能的智能指针类
template <typename T>
class SmartPointer
{
private:
    // 用于保存要被管理对象的指针
    T* m_pointer;
    SmartCount* m_pSmartCount;  // 计数类

public:
    // 构造空指针(形如SmartPointer<int> pi的空指针时)
    explicit SmartPointer();
    //构造函数
    SmartPointer(const T* pointer);
    // 拷贝构造函数
    SmartPointer(const SmartPointer<T>& obj);
    // 析构函数
    ~SmartPointer();
    // 重载指针操作符->
    T* operator->();
    // 重载解引用操作符
    T& operator*();
    // 重载赋值操作符
    void operator=(const SmartPointer<T>& obj);
    // 重载相等判断操作符
    bool operator==(const SmartPointer<T>& obj);
};

// 构造空指针(形如SmartPointer<int> pi的空指针时)
template < typename T >
SmartPointer<T>::SmartPointer() : m_pointer(NULL), m_pSmartCount(NULL)
{
}

// 构造函数(当创建形如SmartPointer<int> pi(new int)或
// SmartPointer<int> pi=new int)
template < typename T >
SmartPointer<T>::SmartPointer(const T* pointer)
{
    m_pointer = const_cast<T*>(pointer);  // 去const属性
    m_pSmartCount = new SmartCount(1);
}

// 拷贝构造函数
template < typename T >
SmartPointer<T>::SmartPointer(const SmartPointer<T>& obj)
{
    m_pointer = obj.m_pointer;
    m_pSmartCount = obj.m_pSmartCount;

    if( m_pSmartCount )
    {
        m_pSmartCount->addRef();
    }
}

// 析构函数
template < typename T >
SmartPointer<T>::~SmartPointer()
{
    if( m_pointer && m_pSmartCount->release() <= 0 )
    {
        delete m_pointer;
        delete m_pSmartCount;
        m_pointer = NULL;
    }
}

// 重载指针操作符->
template < typename T >
T* SmartPointer<T>::operator->()
{
    return m_pointer;
}

// 重载解引用操作符
template < typename T >
T& SmartPointer<T>::operator*()
{
    return *m_pointer;
}

// 重载赋值操作符
template < typename T >
void SmartPointer<T>::operator=(const SmartPointer<T>& obj)
{
    // 判断旧对象是否可删除（如果引用计数release仍大于0，说明原来的堆空间
    // 被其它对象所引用，就不删除旧的堆空间，留给那个引用它的对象去删除）
    if( m_pointer && m_pSmartCount->release() <= 0 )
    {
        delete m_pointer;
        delete m_pSmartCount;
        m_pointer = NULL;
    }

    m_pointer = obj.m_pointer;
    m_pSmartCount = obj.m_pSmartCount;

    if( m_pSmartCount )
    {
        m_pSmartCount->addRef();
    }
};

// 重载相等判断操作符
template < typename T >
bool SmartPointer<T>::operator==(const SmartPointer<T>& obj)
{
    return m_pointer == obj.m_pointer;
}

#endif
