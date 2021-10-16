#include <bits/stdc++.h>
using namespace std;

int solve(string str1, string str2, int n, int m)
{
    if (n == 0)
    {
        int restsum = 0;
        for (int i = 0; i < m; i++)
        {
            restsum += (int)str2[i];
        }
        return restsum;
    }
    if (m == 0)
    {
        int restsum = 0;
        for (int i = 0; i < n; i++)
        {
            restsum += (int)str1[i];
        }
        return restsum;
    }
    if (str1[n] == str2[m])
    {
        return solve(str1, str2, n - 1, m - 1);
    }
    else
    {
        return min((int)str1[n] + solve(str1, str2, n - 1, m), (int)str2[m] + solve(str1, str2, n, m - 1));
    }
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();
    cout << solve(str1, str2, n - 1, m - 1) << endl;
}
//**********************************8
#include <bits/stdc++.h>
using namespace std;

int solve(string str1, string str2, int n, int m)
{
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
                dp[i][j] = dp[i + 1][j] + (int)str2[i];
            }
            else if (i == m)
            {
                dp[i][j] = dp[i][j + 1] + (int)str1[j];
            }
            else
            {
                if (str1[j] == str2[i])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = min((int)str2[i] + dp[i + 1][j], (int)str1[j] + dp[i][j + 1]);
                }
            }
        }
    }
    return dp[0][0];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();
    cout << solve(str1, str2, n, m) << endl;
}