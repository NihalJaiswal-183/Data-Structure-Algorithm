#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int i, j;
    string psf;

public:
    Pair(string psf, int i, int j)
    {
        this->psf = psf;
        this->i = i;
        this->j = j;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int path[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> path[i][j];
        }
    }

    int dp[n][m];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                dp[i][j] = path[i][j];
            }
            else if (i == n - 1)
            {
                dp[i][j] = dp[i][j + 1] + path[i][j];
            }
            else if (j == m - 1)
            {
                dp[i][j] = dp[i + 1][j] + path[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + path[i][j];
            }
        }
    }
    cout << dp[0][0] << endl;
    queue<Pair> bfs;
    bfs.push(Pair("", 0, 0));

    while (bfs.size() > 0)
    {
        Pair rem = bfs.front();
        bfs.pop();
        if (rem.i == n - 1 && rem.j == m - 1)
        {
            cout << rem.psf << endl;
        }

        else if (rem.i == n - 1)
        {
            bfs.push(Pair(rem.psf + "H", rem.i, rem.j + 1));
        }
        else if (rem.j == m - 1)
        {
            bfs.push(Pair(rem.psf + "V", rem.i + 1, rem.j));
        }
        else
        {
            if (dp[rem.i][rem.j + 1] > dp[rem.i + 1][rem.j])
            {
                bfs.push(Pair(rem.psf + "V", rem.i + 1, rem.j));
            }
            else if (dp[rem.i + 1][rem.j] > dp[rem.i][rem.j + 1])
            {
                bfs.push(Pair(rem.psf + "H", rem.i, rem.j + 1));
            }
            else
            {
                bfs.push(Pair(rem.psf + "V", rem.i + 1, rem.j));
                bfs.push(Pair(rem.psf + "H", rem.i, rem.j + 1));
            }
        }
    }
}
