#include <assert.h>
#include <cstring>
using namespace std;

bool matchUnsigned(const char*& str)
{
    bool flag = false;

    while(*str != '\0' && *str >= '0' && *str <= '9')
    {
        str++;
        flag = true;
    }

    return flag;
}

bool matchInt(const char*& str)
{
    if (*str == '+' || *str == '-')
        str++;

    return matchUnsigned(str);
}

bool isNum(const char* str)
{
    if (str == nullptr)
        return false;

    bool numeric = matchInt(str);

    if (*str == '.')
    {
        str++;
        numeric = matchUnsigned(str) || numeric;
    }

    if (*str == 'e' || *str == 'E')
    {
        str++;
        numeric = numeric && matchInt(str);
    }

    return numeric && *str == '\0';
}


int main(int argc, char const *argv[])
{
    assert(isNum("3.14E-15"));
    assert(isNum("5.e2"));
    assert(!isNum(".12e"));
    assert(!isNum("1.2.3"));
    assert(!isNum(".e5"));

    return 0;
}
