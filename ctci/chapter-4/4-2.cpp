#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 100;

bool isRoute(int a, int b, bool graph[][MAX])
{
    if (a == b)
        return true;

    bool isVisited[MAX];
    memset(isVisited, false, sizeof(isVisited));
    queue<int> qu;
    qu.push(a);
    isVisited[a] = true;

    while(!qu.empty())
    {
        int temp = qu.front();
        qu.pop();
        for (int i = 0; i < MAX; i++)
        {
            if (graph[temp][i] != false && isVisited[i] == false)
            {
                if (b == i)
                    return true;

                qu.push(i);
                isVisited[i] = true;
            }
        }
    }

    return false;
}

int main(void)
{

}