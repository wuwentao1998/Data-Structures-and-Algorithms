#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void rearrange(vector<string>& vec)
{
    if (vec.size() <= 2)
        return;

    multimap<string, string> map;
    for (auto str : vec)
    {
        string key = str;
        sort(key.begin(), key.end());
        map.emplace(key, str); // 直接插入应该用emplace，insert的输入应该是一个pair
    }

    vec.clear();
    auto it = map.begin();
    for(; it != map.end(); it++)
        vec.push_back(it->second);
}

int main(void)
{
    vector<string>vec{"abc", "aaaa","bca",  "abccde", "cbed", "edbcac",  "cdeb"};
    rearrange(vec);
}