#include <iostream>

//单利模式1---简单(内存不友好，好用)
class Singleton 
{

public:

    static Singleton* GetInstance() 
    {
        return &m_instance;
    }

    void doSomething() 
    {
        std::cout << "hello world!" << std::endl;
    }

private:
    Singleton() {};
    Singleton(const Singleton &);
    Singleton operator=(const Singleton &);

    static Singleton m_instance;

};
Singleton Singleton::m_instance = Singleton();

//单例模式2---(内存友好，单线程)
// class Singleton 
// {

// public:

//     static Singleton* GetInstance() 
//     {
//         if (m_ptr == NULL) 
//         {
//             m_ptr = new Singleton();
//         }
//         return m_ptr;
//     }

//     void doSomething() 
//     {
//         std::cout << "hello world!" << std::endl;
//     }

// private:
//     Singleton() {};
//     Singleton(const Singleton &);
//     Singleton& operator=(const Singleton &);

//     static Singleton* m_ptr;

// };
// Singleton* Singleton::m_ptr = NULL;

//单利模式3---(内存友好，多线程)
// #include <mutex>
// class Singleton
// {

// public:

//     static Singleton* GetInstance() 
//     {
//         if (m_ptr == NULL) 
//         {
//             std::lock_guard<std::mutex> guard(m_mutex);
//             if (m_ptr == NULL) 
//             {
//                 m_ptr = new Singleton();
//             }
//         }
//         return m_ptr;
//     }
//     void doSomething() 
//     {
//         std::cout << "hello world!" << std::endl;
//     }

// private:
//     Singleton() {};
//     Singleton(const Singleton &);
//     Singleton& operator=(const Singleton &);

//     static Singleton* m_ptr;
//     static std::mutex m_mutex;
// }
// Singleton* Singleton::m_ptr = NULL;


int main() 
{
    Singleton::GetInstance()->doSomething();
    return 0;
}
