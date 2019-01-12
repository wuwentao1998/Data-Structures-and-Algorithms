#include <string>
#include <assert.h>

using namespace std;

bool regexMatch(string str, string pattern)
{
    if (str.empty() || pattern.empty())
        return false;

    int pos = 0;
    int len = pattern.size();
    for (int i = 0; i < len; ++i)
    {
        char c = pattern[i];
        if (c == '.')
        {
            pos++;
            continue;
        }

        if (i != len - 1 && pattern[i + 1] == '*')
        {
            i++;
            while (str[pos] == c)
                pos++;

            continue;
        }

        if (c == str[pos])
            pos++;
        else
            return false;
    }
    if (pos < str.size())
        return false;
    else
        return true;
}

/* 测试代码 */

int main(int argc, char const *argv[])
{
    assert(regexMatch("aaa", "a.a"));
    assert(regexMatch("aaa", "ab*ac*a"));
    assert(!regexMatch("aaa", "aa.a"));
    assert(!regexMatch("aaa", "ab*a"));
    return 0;
}
