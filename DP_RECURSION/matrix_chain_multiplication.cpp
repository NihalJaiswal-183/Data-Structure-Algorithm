#include <bits/stdc++.h>
using namespace std;

int solve(int n, int a[])
{

    int dp[n - 1][n - 1];

    for (int g = 0; g < n - 1; g++)
    {
        for (int i = 0, j = g; j < n - 1; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            else if (g == 1)
            {
                dp[i][j] = a[i] * a[i + 1] * a[i + 2];
            }

            else
            {
                 int minv = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int lc = dp[i][k];
                    int bc = dp[k + 1][j];
                    int mc = a[i] * a[k + 1] * a[j + 1];
                    minv = min(minv, lc + bc + mc);
                }
                dp[i][j] = minv;
            }
        }
    }
    return dp[0][n - 2];
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, a) << endl;
}