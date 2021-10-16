#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str, pattern;
    cin >> str >> pattern;
    int n = pattern.length();
    int m = str.length();

    bool dp[n + 1][m + 1];
    dp[n][m] = true;
    for (int i = 0; i < m; i++)
    {
        dp[n][i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (pattern[i] == '*')
        {
            dp[i][m] = dp[i + 1][m];
        }
        else
        {
            dp[i][m] = false;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (pattern[i] == '?')
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else if (pattern[i] == '*')
            {
                dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
            }
            else
            {
                if (pattern[i] == str[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }
    if (dp[0][0])
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}