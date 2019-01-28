// 把count字节从src指针指向的对象复制到dest指针指向的对象
// 标准库汇总的memcpy如果两个对象有重叠部分，则行为未定义, 我们的实现更接近memmove函数
// 返回值为dest

void* memcopy(void* dest, void* src, unsigned int count)
{
    if (dest == nullptr || src == nullptr || count == 0)
        return nullptr;

    char* cdest = static_cast<char*>(dest); // 不能对void指针执行算数操作，因此需要转为char*类型
    const char* csrc = static_cast<char*>(src);

    if (cdest > csrc && cdest < csrc + count)
    {
        for (int i = count - 1; i >= 0; i--)
            *(cdest + i) = *(csrc + i);
    }

    for (int i = 0; i < count; i++)
        *(cdest++) = *(csrc++);

    return dest;
}
