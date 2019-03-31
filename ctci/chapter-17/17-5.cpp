#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Result
{
    int hits;
    int semi;

    Result(int Hits, int Semi): hits(Hits), semi(Semi) {}

    string toString() { return "Hits: " + to_string(hits) + ", Semi " + to_string(semi); }
};

int code(char c)
{
    switch (c)
    {
        case 'R':
            return 0;
        case 'Y':
            return 1;
        case 'G':
            return 2;
        case 'B':
            return 3;
        default:
            return -1;
    }
}

Result guess_arrange(string guess, string solution)
{
    int hits = 0, semi = 0;

    vector<int> A(4, 0);
    vector<int> B(4, 0);

    for (size_t i = 0; i < guess.size(); i++)
    {
        if (guess[i] == solution[i])
            hits++;
        else
        {
            A[code(solution[i])]++;
            B[code(guess[i])]++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (A[i] > B[i])
            semi += B[i];
        else
            semi += A[i];
    }

    return Result(hits, semi);
}


int main(void)
{
    cout << guess_arrange(string("RGBY"), string("GGRR")).toString();

    return 0;
}
