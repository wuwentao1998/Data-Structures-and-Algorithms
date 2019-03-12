#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<vector<int>> subset(vector<int>& vec)
{
    vector<vector<int>> set;
    if (vec.empty())
        return set;

    for (auto x : vec)
    {
        vector<vector<int>> aux;
        for (auto y : set)
        {
            y.push_back(x);
            aux.push_back(y);
        }
        copy(aux.begin(), aux.end(), back_inserter(set));
        vector<int> t;
        t.push_back(x);
        set.push_back(t);
    }

    return set;
}

int main(void)
{
    vector<int> vec{1,2,3,6};
    auto x = subset(vec);
    return 0;
}