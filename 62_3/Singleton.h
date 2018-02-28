// Singleton.h
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

// boost库的单例类模板（饿汉式，多线程安全的单例模板类）
template <typename T>
struct singleton_default
{
private:
    singleton_default(); // 模板类的构造函数私有化
    // 内部类
    struct object_creator
    {
        object_creator(){singleton_default<T>::instance();}
        inline void do_nothing()const{}
    };

    static object_creator create_object; // 声明：内部类的静态实例

public:
    typedef T object_type;
    static object_type& instance()
    {
        static object_type obj; // 要单例的类实例，放在静态区里

        // 空函数，据说这与模板类的编译有关，可以确保内部类运行该函数时，其
        // 构造函数(调用了{singleton_default<T>::instance())被执行
        create_object.do_nothing();

        return obj;
    }
};

template<typename T>
typename singleton_default<T>::object_creator   // typename==class，内部类类型
singleton_default<T>::create_object;    // 定义内部类的静态实例

#define INSTANCE(class_name) singleton_default<class_name>::instance();

#endif
