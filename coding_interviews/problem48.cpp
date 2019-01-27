// 最长不含重复字符串的子字符串
#include <string>

using namespace std;

#define ALPH 26

int substring(const string& str)
{
    int curlen = 0;
    int maxlen = 0;
    int position[ALPH] = {-1};

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        int pos = position[c];
        int distance = i - pos;

        if (pos == -1 || distance > curlen)
            curlen++;
        else
        {
            if (maxlen < curlen)
                maxlen = curlen;

            curlen = i - pos;
        }

        position[c - 'a'] = i;
    }

    return (maxlen > curlen) ? maxlen : curlen;
}