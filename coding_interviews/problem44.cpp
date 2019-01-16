// 数字序列中的某一位的数字
#include <math.h>

int countOfNumbers(int digits)
{
    if (digits == 1)
        return 10;

    return 9 * (int)std::pow(10, digits - 1);
}

int beginNumber(int digits)
{
    if (digits == 1)
        return 10;

    return (int)std::pow(10, digits - 1);
}

int digitAtIndex(int index, int digits)
{
    int number = beginNumber(digits) + index / digits;
    int indexFromRight = digits - index % digits;

    for (int i = 1; i < indexFromRight; ++i)
        number /= 10;

    return number % 10;
}

 int digitAtIndex(int index)
 {
     if (index < 0)
        return -1;

    int digits = 1;

    while(true)
    {
        int numbers = countOfNumbers(digits);
        if (index < numbers * digits)
            return digitAtIndex(index, digits);

        index -= digits * numbers;
        digits++;
    }

    return -1;
 }