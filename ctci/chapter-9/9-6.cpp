#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

void printBrackt(int n)
{
    if (n <= 0)
        return;

    if (n == 1)
    {
        cout << "()";
        return;
    }
    vector<string> prev;
    prev.push_back("()");
    for (int i = 1; i < n; i++)
    {
        vector<string> cur;
        for (auto x : prev)
        {
            cur.push_back('(' + x + ')');
            string addFront = "()" + x;
            string addBack = x + "()";
            cur.push_back(addFront);
            if (addBack != addFront)
                cur.push_back(addBack);

        }
            prev = cur;
    }

    for (auto str: prev)
        cout << str << endl;
}

void printHelper(string str, int left, int right)
{
    if (left == 0 && right == 0)
    {
        cout << str << endl;
        return;
    }

    if (left > 0)
        printHelper(str + '(', left - 1, right);

    if (right > left)
        printHelper(str + ')', left, right - 1);
}

void printBrackt_v2(int n)
{
    if (n <= 0)
    return;

    if (n == 1)
    {
        cout << "()";
        return;
    }

    printHelper("", n, n);
}

int main(void)
{
    printBrackt_v2(3);
}