// 丑数
bool isUgly(int number)
{
    while (number % 2 == 0)
        number = number / 2;

    while (number % 3 == 0)
        number = number / 3;

    while (number % 5 == 0)
        number = number / 5;

    return number == 1;
}

inline int Min(int a, int b, int c)
{
    int min = (a < b) ? a : b;
    return (min < c) ? min : c;
}

int ugly(int number)
{
    if (number <= 0)
        return 0;

    int* uglyArray = new int[number];
    uglyArray[0] = 1;
    int next = 1;

    int* multiply2 = uglyArray;
    int* multiply3 = uglyArray;
    int* multiply5 = uglyArray;

    while (next < number)
    {
        int min = Min(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
        uglyArray[next] = min;

        while (*multiply2 * 2 <= min)
            multiply2++;

        while (*multiply3 * 3 <= min)
            multiply3++;

        while (*multiply5 * 5 <= min)
            multiply5++;

        next++;
    }

    int ugly = uglyArray[next - 1];
    delete[] uglyArray;
    return ugly;
}
