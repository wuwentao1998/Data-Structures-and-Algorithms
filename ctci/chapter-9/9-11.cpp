#include <string>
#include <unordered_map>
using namespace std;

int f(string& s, bool r, int start, int end, unordered_map<string, int>& map)
{
    string key = s.substr(start, end - start + 1);
    key += r ? "true" : "false";

    if (map.count(key) != 0)
        return map.find(key)->second;

    if (start == end)
    {
        if (s[start] == '1' && r)
            return 1;
        else if (s[start] == '0' && !r)
            return 1;
        else
            return 0;
    }

    int c = 0;
    if (r)
    {
        for (int i = start; i <= end; i++)
        {
            switch (s[i])
            {
                case '&':
                    c += f(s, true, start, i - 1, map) * f(s, true, i + 1, end, map);
                    break;
                case '|':
                    c += f(s, true, start, i - 1, map) * f(s, false, i + 1, end, map);
                    c += f(s, false, start, i - 1, map) * f(s, true, i + 1, end, map);
                    c += f(s, true, start, i - 1, map) * f(s, true, i + 1, end, map);
                    break;
                case '^':
                    c += f(s, true, start, i - 1, map) * f(s, false, i + 1, end, map);
                    c += f(s, false, start, i - 1, map) * f(s, true, i + 1, end, map);
                    break;
                default:
                    break;
            }
        }
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            switch (s[i])
            {
                case '|':
                    c += f(s, false, start, i - 1, map) * f(s, false, i + 1, end, map);
                    break;
                case '&':
                    c += f(s, true, start, i - 1, map) * f(s, false, i + 1, end, map);
                    c += f(s, false, start, i - 1, map) * f(s, true, i + 1, end, map);
                    c += f(s, false, start, i - 1, map) * f(s, false, i + 1, end, map);
                    break;
                case '^':
                    c += f(s, true, start, i - 1, map) * f(s, true, i + 1, end, map);
                    c += f(s, false, start, i - 1, map) * f(s, false, i + 1, end, map);
                    break;
                default:
                    break;
            }
        }
    }

    map[key] = c;
    return c;
}

int fun(string s, bool r)
{
    int len = s.size();
    unordered_map<string, int> map;
    return f(s, r, 0, len - 1, map);
}

int main(void)
{
    string s = "1&0&1|1";
    int result = fun(s, true);
    return 0;
}