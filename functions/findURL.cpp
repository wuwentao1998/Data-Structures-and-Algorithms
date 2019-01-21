// 查找文本中的全部URL

#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

typedef string::const_iterator const_iter;
bool error = false;

bool notUrl(char c)
{
    static const string url = "~;/?:@=&$-.+!*'(),"; // 静态变量避免频繁初始化

    bool isURL = isalnum(c) || (find(url.begin(), url.end(), c) != url.end());
    return !isURL;
}

const_iter urlBegin(const_iter begin, const_iter end)
{
    static const string token = "://";
    const_iter i = begin;

    // 因为即使找到token也不一定是合法的url，此时要继续找，所以使用while而不是if
    while ((i = search(i, end, token.begin(), token.end())) != end)
    {
        const_iter tempBegin = i;
        while (tempBegin != begin && isalpha(*(tempBegin - 1)))
            tempBegin--;

        // 判断是否token前后都有合法内容
        if (tempBegin != i && i + token.size() != end && !notUrl(*(i + token.size())))
            return tempBegin;
        else
            i += token.size();
    }

    return end;
}


inline const_iter urlAfter(const_iter begin, const_iter end)
{
    return find_if(begin, end, notUrl);
}

vector<string> findURL(const string& str)
{
    vector<string> vec;
    if (str.empty())
    {
        error = true;
        return vec;
    }

    auto begin = str.begin();
    auto end = str.end();

    while (begin != end)
    {
        begin = urlBegin(begin, end);

        if (begin != end)
        {
            const_iter after = urlAfter(begin, end);
            vec.push_back(string(begin, after));
            begin = after;
        }
    }

    return vec;
}