// 把数字翻译成字符串
#include <string>
#include <assert.h>
#include <vector>
using namespace std;

// 递归版

void transform(string str, int& count)
{
    if (str.empty())
    {
        count++;
        return;
    }

    if (str.size() >= 2 & (str[0] == '2' ||str[0] == '1') && str[1] <= '5')
        transform(str.substr(2), count);

    transform(str.substr(1), count);
}

// 循环版
void transform_v2(string str, int& count)
{
    int len = str.size();
    vector<int> counts;
    counts.resize(len);

    for (int i = len - 1; i >= 0; --i)
    {
        count = 0;
        if (i < len - 1)
            count = counts[i + 1];
        else
            count = 1;

        if (i < len - 1)
        {
            int digit1 = str[i] - '0';
            int digit2 = str[i + 1] - '0';
            int merge = digit1 * 10 + digit2;

            if (merge >= 10 && merge <= 25)
            {
                if ( i < len - 2)
                    count += counts[i+ 2];
                else
                    count++;

            }
        }

        counts[i] = count;
    }

    count = counts[0];
}

int transform(int num)
{
    if (num < 0)
        return 0;

    string str = to_string(num);
    int count = 0;
    transform_v2(str, count);
    return count;
}



/* 测试代码 */

int main(int argc, char const *argv[])
{
    assert(transform(12258) == 5);
    return 0;
}