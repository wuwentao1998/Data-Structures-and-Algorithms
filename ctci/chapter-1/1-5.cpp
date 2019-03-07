#include <string>
#include <iostream>
using std::string;

string compress(string& str)
{
    if (str.size() <= 1)
        return str;

    int num = 1;
    char lastChar = str[0];
    string newStr;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == lastChar)
            num++;
        else
        {
            newStr.push_back(lastChar);
            newStr.push_back(num +'0');
            num = 1;
            lastChar = str[i];
        }
    }
    newStr.push_back(lastChar);
    newStr.push_back(num + '0');
    if (newStr.size() < str.size())
        return newStr;
    else
        return str;
}

int main(void)
{
    string str("aabccccaaa");
    std::cout << compress(str);
}