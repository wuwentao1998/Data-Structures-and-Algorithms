#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;


// 只调用一次时的解法， O(n)
int shortest_v1(vector<string> words, string s1, string s2)
{
    int min = INT_MIN;
    int pos1 = -1;
    int pos2 = -1;

    for (int i = 0; i < words.size(); i++)
    {
        string cur = words[i];
        if (cur == s1)
        {
            pos1 = i;
            int distance = pos1 - pos2;
            if (pos2 > 0 && distance < min)
                min = distance;
        }
        else if (cur == s2)
        {
            pos2 = i;
            int distance = pos2 - pos1;
            if (pos1 > 0 && distance < min)
                min = distance;
        }
    }

    return min;
}

// 调用多次时的解法，O(n)
unordered_map<string, vector<int>> map;

void buildMap(vector<string> words)
{
    for (int i = 0; i < words.size(); i++)
        map[words[i]].push_back(i);
}

int shortest_v2(string s1, string s2)
{
    vector<pair<int, bool>> vec;
    if (map.count(s1) > 0 && map.count(s2) > 0)
    {
        for (auto x : map.find(s1)->second)
            vec.push_back(make_pair(x, true));

        for (auto x: map.find(s2)->second)
            vec.push_back(make_pair(x, false));

        sort(vec.begin(), vec.end());

        int min = INT_MAX;
        int pos1 = -1;
        int pos2 = -1;
        for (int i = 0; i < vec.size(); i++)
        {
            auto cur = vec[i];
            if (cur.second)
            {
                pos1 = vec[i].first;
                int distance = pos1 - pos2;
                if (pos2 > -1 && distance < min)
                    min = distance;

            }
            else
            {
                pos2 = vec[i].first;
                int distance = pos2 - pos1;
                if (pos1 > -1 && distance < min)
                    min = distance;
            }
        }

        return min;
    }
    else
        return -1;
}

int main(void)
{
    string s[9]{"ha", "ba","ez","pop","hei","nani","baba","ha","pi"};
    vector<string> words;
    copy(s, s + 9, back_inserter(words));
    buildMap(words);
    auto a = shortest_v2("ha", "hei");
    return 0;
}