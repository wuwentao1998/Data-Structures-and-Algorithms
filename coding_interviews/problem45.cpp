// 把数组排成最小的数
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const string& a, const string& b)
{
    string cp1 = a + b;
    string cp2 = b + a;

    return cp1 < cp2;
}

void printMin(int* array, int len)
{
    if (array == nullptr || len <= 0)
        return;

    vector<string> strNumbers;
    for (int i = 0; i < len; ++i)
        strNumbers.push_back(to_string(array[i]));

    sort(strNumbers.begin(), strNumbers.end(), compare);

    for(auto a: strNumbers)
        cout << a;

    cout << endl;
}

/* 测试代码 */

int main(int argc, char const *argv[])
{
    int a[] = {3,32,321};
    int b[] = {123, 4, 56};
    printMin(a, 3);
    printMin(b, 3);
    return 0;
}
