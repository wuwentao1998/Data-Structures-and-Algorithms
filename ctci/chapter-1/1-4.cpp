#include <cstring>
#include <iostream>

void replace(char* str)
{
    if (str == nullptr || *str == '\0')
        return;

    int num = 0;
    char* t = str;
    while (*t != '\0')
    {
        if(*t == ' ')
            num++;

        t++;
    }

    int offset = num * 2;
    while(--t != str)
    {
        if (*t != ' ')
            *(t + offset) = *t;
        else
        {
            offset -= 2;
            *(t + offset) = '%';
            *(t + offset + 1) = '2';
            *(t + offset + 2) = '0';
        }
    }
}

int main(void)
{
    char* str = new char[50];
    strcpy(str, "I am your father. ");
    replace(str);
    std::cout << str;
}