#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
        if (a.first < b.first)
            return true;
        else
            return false;
}

int maxPerson(vector<pair<int, int>>& vec)
{
    if (vec.empty())
        return 0;

    sort(vec.begin(), vec.end(), cmp);
    vector<vector<int>> weight;
    for (auto p : vec)
    {
        int flag = true;
        for (auto& x : weight)
        {
            if (p.second >= x.back())
            {
                flag = false;
                x.push_back(p.second);
            }
        }

        if (flag)
        {
            vector<int> v;
            v.push_back(p.second);
            weight.push_back(v);
        }
    }

    unsigned int max = 0;
    for (auto x : weight)
    {
        if (x.size() > max)
            max = x.size();
    }

    return max;
}

int main(void)
{

}

