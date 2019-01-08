// 单例模式
#include <mutex>


// 饿汉版本

class Singleton_2
{
public:
    Singleton_2(const Singleton_2 &) = delete;
    Singleton_2 &operator=(const Singleton_2 &) = delete;
    static Singleton_2 &getInstance()
    {
        return instance;
    }

private:
    Singleton_2() {}
    ~Singleton_2() {}

    static Singleton_2 instance;
};

Singleton_2 Singleton_2::instance;



// 懒汉版本

class Singleton_3
{
public:
    Singleton_3(const Singleton_3 &) = delete;
    Singleton_3 &operator=(const Singleton_3 &) = delete;
    static Singleton_3 &getInstance()
    {
        if (instance == nullptr) //避免已经创建好实例后还要加锁解锁
        {
            mt.lock();
            if (instance == nullptr)
                instance = new Singleton_3;
            mt.unlock();
        }

        return *instance;
    }

private:
    Singleton_3() {}
    ~Singleton_3() {}

    static Singleton_3 *instance;
    static std::mutex mt;
};

Singleton_3 *Singleton_3::instance = nullptr;
std::mutex Singleton_3::mt;



// c++11后的懒汉版本

class Singleton_1
{
  public:
    Singleton_1(const Singleton_1 &) = delete;
    Singleton_1 &operator=(const Singleton_1 &) = delete;
    static Singleton_1 &getInstance()
    {
        static Singleton_1 instance; // C++11下局部静态变量是线程安全的,并且保证了在第一次调用时才创建实例
        return instance;
    }

  private:
    Singleton_1() {}
    ~Singleton_1() {}
}; // 不要忘了分号