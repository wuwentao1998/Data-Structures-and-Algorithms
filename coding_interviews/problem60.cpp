#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
// n个骰子的点数
#define MAX 6

//#define DEBUG
// 解法一：递归

void probability(int num, int* array, int pos, int sum)
{
    if (pos == num)
    {
        array[sum - num]++;
        return;
    }

    for (int i = 1; i <= MAX; i++)
        probability(num, array, pos + 1, sum + i);
}


void printProbability(int num)
{
    if (num < 1)
        return;

    int allProbability = pow(6, num);
    int* prob = new int[MAX * num - num + 1];
    memset(prob, 0, sizeof(int) * (MAX * num - num + 1)); // prob是一个指针，sizeof(prob)是一个指针的大小，而非数组大小

    #ifdef DEBUG

    for (int i = num; i <= MAX * num; i++)
        cout << prob[i - num] << " ";

    #endif

    probability(num, prob, 0, 0);

    for (int i = num; i <= MAX * num; i++)
        cout << prob[i - num] << " ";

    cout << endl;
    delete[] prob;
}


// 解法二：循环

void printProbability_2(int num)
{
    if (num < 1)
        return;

    int* prob[2];
    prob[0] = new int[MAX * num + 1];
    prob[1] = new int[MAX * num + 1];
    memset(prob[0], 0, sizeof(int) * (MAX * num + 1));
    memset(prob[1], 0, sizeof(int) * (MAX * num + 1));

    for (int i = 1; i <= MAX; i++)
        prob[0][i] = 1;

    int flag = 1;

    for (int j = 2; j <= num; j++)
    {
        for (int i = 0; i < j; i++)
            prob[flag][i] = 0;

        for (int k = j; k <= MAX * j; k++)
        {
            prob[flag][k] = 0;
            for (int i = 1; i <= k && i <= MAX; i++)
                prob[flag][k] += prob[1 - flag][k - i];
        }

        flag = 1 - flag;
    }

    int allProbability = pow(6, num);
    for (int i = num; i <= MAX * num; i++)
        cout << prob[1 - flag][i] << " ";

    cout << endl;
    delete[] prob[0];
    delete[] prob[1];
}


/* 测试代码 */

int main(int argc, char* argv[])
{
    printProbability_2(2);
    return 0;
}