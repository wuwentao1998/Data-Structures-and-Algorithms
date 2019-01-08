// 为类型MyStr添加赋值运算符
#include <string.h>
#include <stdlib.h>

class MyStr
{
public:
    MyStr(char *ptr = nullptr);
    MyStr(const MyStr &str) { copy(str); }
    ~MyStr();
    MyStr &operator=(const MyStr &str) { return copy(str); }

private:
  MyStr &copy(const MyStr &str); // 返回引用，从而能够连续赋值
private:
    char *_ptr;
};

inline MyStr &MyStr::copy(const MyStr &str)
{
    if (&str != this) // 如果忘记判断则会错误释放本身已有空间
    {
        delete _ptr; // 首先应该方式已有空间，防止内存泄漏
        _ptr = new char[strlen(str._ptr) + 1]; // strlen计算的长度不包含末尾的0，所以应该加1
        strcpy(_ptr, str._ptr);
    }
    return *this;
}



