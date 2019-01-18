#include <iostream>
using namespace std;

// 问题1：和为s的两个数字

bool sumS(int* array, int len, int s, int* num1, int* num2)
{
    if (array == nullptr || len <2 || num1 == nullptr || num2 == nullptr)
        return false;

    int begin = 0;
    int end = len - 1;

    while (end > begin)
    {
        int curSum = array[begin] + array[end];

        if (curSum == s)
        {
            *num1 = begin;
            *num2 = end;
            return true;
        }
        else if (curSum < s)
            begin++;
        else
            end--;
    }

    return false;
}

// 问题2：和为s的连续正数列
void printSequence(int begin, int end)
{
    for (int i = begin; i <= end; i++)
        cout << i << " ";

    cout << endl;
}

void printSum(int sum)
{
    if (sum < 3)
        return;

    int begin = 1;
    int end = 2;
    int mid = (1 + sum) / 2;
    int curSum = begin + end;

    while (begin < mid)
    {
        if (curSum == sum)
        {
            printSequence(begin, end);
            curSum -= begin;
            begin++;
        }
        else if (curSum < sum)
        {
            end++;
            curSum += end;
        }
        else
        {
            curSum -= begin;
            begin++;
        }
    }
}

int main(int argc, char const *argv[])
{
    printSum(15);
    return 0;
}

