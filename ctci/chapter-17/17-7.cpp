#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

static string seperators[] {"", "Thousand", "Million", "Billion"};
static string tens[] {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
static string teens[] {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
static string digits[] {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

string numToString100(int val)
{
    string str;

    if (val >= 100)
    {
        str += digits[val / 100 - 1] + " Hundred "; // 下标从0开始
        val = val % 100;
    }

    if (val >= 11 && val <= 19)
        str += teens[val - 11] + " ";
    else if (val == 10 || val >= 20)
    {
        str += tens[val / 10 - 1] + " ";
        val = val % 10;
    }

    if (val != 0)
        str += digits[val - 1] + " ";

    return str;
}

void printInt(int val)
{

    if (val == 0)
        cout << "Zero";

    bool negative = false;
    if (val < 0)
    {
        negative = true;
        val = -val;
    }

    string str;
    int count = 0;

    while (val > 0)
    {
        if (val % 1000 != 0)
            str = numToString100(val % 1000) + seperators[count] + ", " + str;

        val /= 1000;
        count++;
    }

    if (negative)
        str = "Negative " +str;

    cout << str;
}


int main(void)
{
    printInt(-1234);
}