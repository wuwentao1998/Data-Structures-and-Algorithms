#include<iostream>
#include<string>
using namespace std;

string decimalToBinary(double a)
{
    if(a<0 || a>= 1)
        return "ERROR!";
    string res="";
    res = res + "0.";
    while (a > 0)
    {
        if(res.size() > 32)
            return "ERROR!";

        a *= 2;
        if (a >1)
        {
            a -= 1.0;
            res += '1';
        }
        else
            res += '0';
    }

    return res;
}