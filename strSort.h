#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define RANGE 256

int charAt(string &s, size_t w);
void swap(string &a, string &b);

void LSD(vector<string> &v, size_t w)
{
    for (int i = w - 1; i >=0 ; i--)
    {
        vector<string> t;
        size_t n = v.size();
        t.resize(n); // 必须使用resize而不是reserve，否则未分配元素，只能使用insert或者push_back，不可使用下标
        int count[RANGE + 1] = {0};

        for (auto s : v)
            count[s[i] + 1]++;

        for (int j = 1; j < RANGE; j++)
            count[j] += count[j - 1]; //count的第j格表示小于等于j的所有键的数量的和，由于计数从0开始，键为j的元素应该从第count[j]格开始出现

        for (auto s : v)
            t[count[(size_t)s[i]]++] = s;

        copy(t.begin(), t.end(), v.begin());

    }
}

void MSD(vector<string> &v, int begin, int end, size_t w)
{
    if (begin >= end)
        return;

    size_t size = end - begin + 1;
    vector<string> aux;
    aux.resize(size);
    int count[RANGE + 2] = {0};

    for (int i = begin; i <= end; i++)
        count[charAt(v[i], w) + 2]++;

    for (int i = 1; i < RANGE + 1; i++)
        count[i] += count[i - 1];

    for (int i = begin; i <= end; i++)
        aux[count[charAt(v[i], w) + 1]++] = v[i]; //结束后count[r]中数据的意义为r键最后一个位置加1

    copy(aux.begin(), aux.end(), v.begin() + begin);

    for (int r = 0; r < RANGE; r++)
        MSD(v, begin + count[r], begin + count[r + 1] - 1, w + 1);
}

void Quick3string(vector<string> &v, int low, int high, size_t w)
{
    if (high <= low)
        return;
    int partition = low + rand() % (high - low);
    swap(v[low], v[partition]);

    int lt = low;
    int gt = high;
    int i = low + 1;
    int ch = charAt(v[low], w);

    while (i <= gt)
    {
        int t = charAt(v[i], w);
        if (t < ch)
            swap(v[lt++], v[i++]);
        else if (t > ch)
            swap(v[gt--], v[i]);
        else
            i++;
    }

    Quick3string(v, low, lt - 1, w);

    if (ch >= 0) // 判断是否为空
        Quick3string(v, lt, gt, w + 1);

    Quick3string(v, gt + 1, high, w);

}


/*辅助函数*/

int charAt(string &s, size_t w)
{
    if (w < s.size())
        return (int)s[w];
    else
        return -1;
}

void swap(string &a, string &b)
{
    string temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}
