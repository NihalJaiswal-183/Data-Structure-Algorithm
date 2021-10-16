

#include <bits/stdc++.h>
using namespace std;

int findMinCost(string X, string Y, int costX, int costY)
{
    int n = X.length();
    int m = Y.length();
    int dp[m + 1][n + 1];
    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i == m && j == n)
            {
                dp[i][j] = 0;
            }
            else if (j == n)
            {
                dp[i][j] = dp[i + 1][j] + costY;
            }
            else if (i == m)
            {
                dp[i][j] = dp[i][j + 1] + costX;
            }
            else
            {
                if (X[j] == Y[i])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = min(costY + dp[i + 1][j], costX + dp[i][j + 1]);
                }
            }
        }
    }
    return dp[0][0];
}
int main()
{
    string X, Y;
    cin >> X >> Y;
    int costX, costY;
    cin >> costX >> costY;

    cout << findMinCost(X, Y, costX, costY) << endl;
}