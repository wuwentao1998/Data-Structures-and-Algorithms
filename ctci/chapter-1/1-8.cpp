#include <string>
#include <algorithm>
using std::search;
using std::string;

bool isRotation(string a, string b)
{
    if (a.size() != b.size())
        return false;

    string aa = a + a;
    return search(aa.begin(), aa.end(), b.begin(), b.end()) != aa.end();
}

int main(void)
{
    string a = "1234";
    string b = "3412";
    bool flag = isRotation(a, b);
}