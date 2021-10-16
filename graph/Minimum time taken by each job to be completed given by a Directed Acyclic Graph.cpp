#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

vector<int> graph[maxN];

int indegree[maxN];

int job[maxN];

void addEdge(int u, int v)
{

    graph[u].push_back(v);

    indegree[v]++;
}

void printOrder(int n, int m)
{
    queue<int> bfs;
    int t = 1;
    for (int i = 1; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            bfs.push(i);
        }
    }
    while (bfs.size() > 0)
    {
        int s = bfs.size();
        for (int i = 0; i < s; i++)
        {
            int rem = bfs.front();
            job[rem] = t;
            bfs.pop();
            for (auto x : graph[rem])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    bfs.push(x);
                }
            }
        }
        t++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << job[i] << " ";
    }
}
int main()
{

    int n, m;
    n = 10;
    m = 13;

    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);

    printOrder(n, m);
    return 0;
}