// HeapArray.h 数组类头文件
#ifndef _HEAPARRAY_H_
#define _HEAPARRAY_H_

template < typename T >
class HeapArray
{
private:
    int m_length;
    T *m_pointer;

    HeapArray(int len);  // 第一阶构造函数
    bool construct();    // 第二阶构造函数
public:  
    static HeapArray<T>* NewInstance(int len);

    HeapArray(const HeapArray<T>& obj);  // 继续保留拷贝构造函数是公有的
    HeapArray<T>& operator = (const HeapArray<T>& obj);  // 重载赋值操作符

    ~HeapArray();
    int length();
    bool setValue(int index, T value);
    bool getValue(int index, T &value);

    T& operator [] (int index);
    T operator [] (int index) const;
    HeapArray<T>& self();   // 因为该类只能在堆在创建对象，为了操作方便
                            // 通过这里返回对象的引用，可以避开指针操作的麻烦
    HeapArray<T>& self() const;
};

// 第一阶构造：资源无关的初始化
template < typename T >
HeapArray<T>::HeapArray(int len)
{
    m_length = len;
}

// 第二阶构造：系统资源的申请操作
template < typename T >
bool HeapArray<T>::construct()
{
    m_pointer = new T[m_length];

    return m_pointer != NULL;
}

template < typename T >
HeapArray<T>* HeapArray<T>::NewInstance(int len)
{
    HeapArray<T>* obj = new HeapArray<T>(len);

    if( !(obj && obj->construct()) )
    {
        delete obj;
        obj = NULL;
    }

    return obj;
}

// 拷贝构造（成员m_pointer指向了动态内存空间,所以应该是深拷贝）
template < typename T >
HeapArray<T>::HeapArray(const HeapArray& obj)
{
    m_length = obj.m_length;
    m_pointer = new T[obj.m_length];

    for(int i=0; i<obj.m_length; i++)
    {
        m_pointer[i] = obj.m_pointer[i];
    }
}

template < typename T >
HeapArray<T>& HeapArray<T>::operator = (const HeapArray<T>& obj)
{
    if( this != &obj )
    {
        /*
        delete m_pointer;

        //错误,const对象不能调用非const成员函数
        //m_pointer = new int[obj.length()];
        m_pointer = new int[obj.m_length];

        for(int i=0; i<obj.m_length; i++)
        {
            m_pointer[i] = obj.m_pointer[i];
        }
        */

        // 下面语句更安全，先以一个临时指针接收obj.m_pointer
        // 可以防止上面 delete m_pointer 后 new 又不成功的情况
        // 这个时候那么m_pointer就成为了野指针
        // 而下面的代码怎么都不会有野指针产生
        T* pointer = new T[obj.m_length];

        if( pointer )
        {
            for(int i=0; i<obj.m_length; i++)
            {
                pointer[i] = obj.m_pointer[i];
            }

            m_length = obj.m_length;  // 这个一定不要忘了
            delete m_pointer;
            m_pointer = pointer;
        }
    }

    return *this;
}

template < typename T >
HeapArray<T>::~HeapArray()
{
    if(m_pointer)
    {
        delete []m_pointer;
    }
}

template < typename T >
int HeapArray<T>::length()
{
    return m_length;
}

template < typename T >
bool HeapArray<T>::setValue(int index, T value)
{
    bool bRet = ( 0 <= index ) && ( index < m_length);

    if(bRet)
    {
        m_pointer[index] = value;
    }

    return bRet;
}

template < typename T >
bool HeapArray<T>::getValue(int index, T &value)
{
    bool bRet = (0 <= index ) && (index < m_length);

    if(bRet)
    {
        value = m_pointer[index];
    }

    return bRet;
}

template < typename T >
T& HeapArray<T>::operator [] (int index)
{
    if( (0 <= index ) && (index < m_length) )
    {
        return m_pointer[index];
    }
}

template < typename T >
T HeapArray<T>::operator [] (int index) const
{
    if( (0 <= index ) && (index < m_length) )
    {
        return m_pointer[index];
    }
}

template < typename T >
HeapArray<T>& HeapArray<T>::self()
{
    return *this;
}

template < typename T >
HeapArray<T>& HeapArray<T>::self() const
{
    return *this;
}

#endif
