// 从文本文件中读取单词，排序单词出现的次数。用set排除某些特定单词，例如 the, an, but等。
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    set<string> filter {"a", "an", "the", "and", "but"};
    map<string, int> dic;

    string word;
    while (cin >> word)
    {
        if (filter.find(word) == filter.end())
        {
            auto iter = dic.find(word);

            // 或者可以简写为：dic[word]++;
            if (iter == dic.end())
                dic.emplace(word, 1);
            else
                iter->second++;
        }
    }

    for (auto pair: dic)
        cout << pair.first << " : " << pair.second << "times" << endl;

    return 0;
}

