#include <bits/stdc++.h>
using namespace std;

int lrs(string str, int n1, int n2)
{

    if (n1 < 0 | n2 < 0)
    {
        return 0;
    }

    if (str[n1] == str[n2] && n1 != n2)
    {
        return 1 + lrs(str, n1 - 1, n2 - 1);
    }
    else
    {
        return max(lrs(str, n1 - 1, n2), lrs(str, n1, n2 - 1));
    }
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    cout << lrs(str, n - 1, n - 1);
}

//*********************************************************

#include <bits/stdc++.h>
using namespace std;

int lrs(string str, int n)
{

    int dp[n][n];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1)
            {
                dp[i][j] = 0;
            }
            else if (j == n - 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (str[i] == str[j] && i != j)
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
    }
    return dp[0][0];
}

int main()
{
    string str;
    cin >> str;

    int n = str.length();
    cout << lrs(str, n + 1);
}