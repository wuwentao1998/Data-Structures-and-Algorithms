#include <string>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

const int ALPH = 256;

bool isTransferable(string str1, string str2)
{
    if (str1.size() != str2.size())
        return false;

    int ascii[ALPH]; // 由于可能存在相同字母，故不能用bool
    memset(&ascii, 0, sizeof(int) * ALPH);

    for (auto c: str1)
        ascii[c]++;

    for (auto c: str2)
    {
        if (--ascii[c] < 0)
            return false;
    }

    return true;
}

int main(void)
{
    string a("123");
    string b("312");
    string c("314");

    cout << isTransferable(a, b) << endl;
    cout << isTransferable(b, c);
}