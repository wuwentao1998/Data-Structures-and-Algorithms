// 分割字符串

#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


inline bool notSpace(char c)
{
    return !isspace(c);
}

// 因为isspace是c标准库中的函数，返回值为int，所以要在外面包装一层函数
inline bool space(char c)
{
    return isspace(c);
}

// 普通版本

vector<string> split(const string& str)
{
    vector<string> vec;

    auto begin = str.begin();
    auto end = str.end();
    while (begin != str.end())
    {
        begin = find_if(begin, str.end(), notSpace);
        end = find_if(begin, str.end(), space);

        if (begin != str.end())
            vec.push_back(string(begin, end));

        begin = end;
    }

    return vec;
}

// 为了提高适应性，我们增加一个输出迭代器参数以替代返回值
// 使用范例：split(str, back_insert(word_list));

template <typename Out>
void split(const string& str, Out os)
{
    auto begin = str.begin();
    auto end = str.end();
    while (begin != str.end())
    {
        begin = find_if(begin, str.end(), notSpace);
        end = find_if(begin, str.end(), space);

        if (begin != str.end())
            (*os)++ = string(begin, end);

        begin = end;
    }
}


