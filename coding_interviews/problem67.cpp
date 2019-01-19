// 把一个字符串转为整数

#include <string>
#include <cstring>
#include <ctype.h>
#include <assert.h>

int str2int(const char *str)
{
    if (str == nullptr)
        throw "wrong input: null pointer";

    while(*str != 0 && isblank(*str))
        str++;

    if (*str == 0)
        throw "wrong input: empty string";


    bool isNegative = false;
    if (*str == '+')
        str += 1;
    if (*str == '-')
    {
        isNegative = true;
        str += 1;
    }

    if (!isdigit(*str))
        throw "wrong input: not a number";

    int result = 0;
    while (*str != 0 && isdigit(*str))
    {
        result = result * 10 + *str - '0';
        if (result < 0)
            throw "wrong input: overflow";

        ++str;
    }

    if (isNegative)
        result = 0 - result;

    return result;
}

const char* exception (const char* str)
{
    try
    {
        str2int(str);
    }
    catch(const char* error)
    {
        return error;
    }
    return "no exception";
}

/* 测试代码 */

int main(int argc, char const *argv[])
{
    assert(strcmp(exception(nullptr), "wrong input: null pointer") == 0);
    assert(strcmp(exception(""), "wrong input: empty string") == 0);
    assert(strcmp(exception("9999999999999999999999999"), "wrong input: overflow") == 0);
    assert(strcmp(exception("asdf234465"), "wrong input: not a number") == 0);

    assert(str2int("123") == 123);
    assert(str2int("-567sadf") == -567);
    assert(str2int("  467") == 467);

    return 0;
}
