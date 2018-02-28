// Singleton.h 单例类模板
#ifndef SINGLETON_H
#define SINGLETON_H

template < typename T >
class Singleton
{
private:
    static T* c_instance;

public:
    static T* GetInstance();
};

template < typename T >
T* Singleton<T>::c_instance = NULL;

template < typename T >
T* Singleton<T>::GetInstance()
{
    if( NULL == c_instance )
    {
        c_instance = new T;
    }

    return c_instance;
}

#endif
