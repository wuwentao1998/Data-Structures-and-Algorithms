#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> dic;

bool helper(string origin, string dest, set<string>& sets)
{
    if (origin == dest)
        return true;

    if (sets.count(origin) > 0 || dic.count(origin) == 0)
        return false;

    for (int i = 0; i < origin.size(); i++)
    {
        if (origin[i] == dest[i])
            continue;

        string intermediate = origin;
        intermediate[i] = dest[i];
        if (helper(intermediate, dest, sets))
            return true;
        else
            sets.insert(intermediate);
    }

    return false;
}

bool changable(string origin, string dest)
{
    set<string> sets;

    return helper(origin, dest, sets);
}

int main(void)
{
    dic.insert("DAMP");
    dic.insert("LAMP");
    dic.insert("LIKE");
    dic.insert("LIMG");
    dic.insert("LIMP");
    dic.insert("LALA");

    bool t = changable("DAMP", "LIKE");

    return 0;
}