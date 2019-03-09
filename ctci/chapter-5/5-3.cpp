int minBigger(unsigned int x)
{
    int ones = 0;
    int offset = 0;
    while (offset < 32)
    {
        if (x & (1 << offset))
            break;
        else
            offset++;
    }

    if (offset >= 31)
        return -1;

    while(offset < 32)
    {
        if (x &(1 << offset))
        {
            ones++;
            offset++;
        }
        else
            break;
    }

    if (offset >= 32)
        return -1;

    x |= 1 << offset;
    x &= ~((1 << offset) - 1);
    x |= (1 << (ones - 1)) - 1;
}