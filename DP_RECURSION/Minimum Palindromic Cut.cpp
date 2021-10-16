#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(string X, int i, int j)
{
    while (i <= j)
    {
        if (X[i++] != X[j--])
            return false;
    }
    return true;
}

int minPalinPartition(string X, int i, int j)
{

    if (isPalindrome(X, i, j))
        return 0;

    int minans = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        minans = min(minans, 1 + minPalinPartition(X, i, k) +
                                 minPalinPartition(X, k + 1, j));
    }
    return minans;
}

int main()
{
    string X;
    cin >> X;
    int n = X.length();

    cout << minPalinPartition(X, 0, n - 1);

    return 0;
}

//******************************************

#include <bits/stdc++.h>
using namespace std;

int solve(string str)
{
    int n = str.length();
    bool dp[n][n] = {false};

    int count = 0;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                if (str[i] == str[j])
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }

            else
            {
                if (str[i] == str[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }
    int ansdp[n][n];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                ansdp[i][j] = 0;
            }
            else if (g == 1)
            {
                if (str[i] == str[j])
                {
                    ansdp[i][j] = 0;
                }
                else
                {
                    ansdp[i][j] = 1;
                }
            }
            else
            {
                int minv = INT_MAX;
                if (dp[i][j])
                {

                    ansdp[i][j] = 0;
                }
                else
                {
                    for (int k = i; k < j; k++)
                    {
                        int lc = ansdp[i][k];
                        int bc = ansdp[k + 1][j];
                        minv = min(minv, lc + bc);
                    }
                    ansdp[i][j] = minv + 1;
                }
            }
        }
    }
    return ansdp[0][n - 1];
}

int main()
{

    string str;
    cin >> str;

    cout << solve(str) << endl;
}