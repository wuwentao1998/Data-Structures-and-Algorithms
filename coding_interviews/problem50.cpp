// 第一个只出现一次的字符

#include <cstring>
#define ALPH 26
char firstChar(const char* str)
{
    if (str == nullptr ||strlen(str) == 0)
        return '\0';

    int hash[ALPH] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        hash[str[i] - 'a']++;

    for (int i = 0; i < len; ++i)
    {
        if (hash[str[i] - 'a'] == 1)
            return str[i];
    }

    return '\0';
}




