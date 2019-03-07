void rotate(int** image, int n)
{
    if (image == nullptr || n <= 1)
        return;

    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - 1 -layer;
        for (int i = first; i < last; i++)
        {
            int offset = i - first;
            int top = image[first][i];
            image[first][i] = image[last - offset][first];
            image[last - offset][first] = image[last][last - offset];
            image[last][last - offset] = image[i][last];
            image[i][last] = top;
        }
    }
}

