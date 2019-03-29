#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

// 为了从大到小排列，这里为大于号
class Comp
{
public:
    bool operator()(const string& a, const string& b)
    {
        if (a.size() == b.size()) // 如果缺少这一部分，则同样长度的string只出现一个
            return a > b;
        else
            return a.size() > b.size();
    }
};

bool isContain(string cur, map<string, bool>& combines, bool isOrigin)
{
    if (!isOrigin && combines.count(cur) > 0)
        return combines.find(cur)->second;

    for (int i = 1; i < cur.size(); i++)
    {
        string left = cur.substr(0, i);
        string right = cur.substr(i);
        if (combines.count(left) == 0)
        {
            combines.emplace(left, false);
            continue;
        }

        if (combines.count(left) > 0 && !combines.find(cur)->second)
            continue;

        if (isContain(right, combines, false))
            return true;
        else
        {
            combines.emplace(right, false);
            continue;
        }
    }

    return false;
}

string maxStr(vector<string> words)
{
    set<string, Comp> sets;
    map<string, bool> combines;
    for(auto x: words)
    {
        sets.insert(x);
        combines.emplace(x, true);
    }

    auto begin = sets.begin();
    while (begin != sets.end())
    {
        string cur = *begin;
        if (isContain(cur, combines, true))
            return cur;

        begin++;
    }

    return string("");
}

int main(void)
{
    string s[7]{"cat", "ban","dog","nana","walk","dogwalker", "qwertyuiopasdf"};
    vector<string> words;
    copy(s, s + 7, back_inserter(words));

    string m = maxStr(words);

    return 0;
}