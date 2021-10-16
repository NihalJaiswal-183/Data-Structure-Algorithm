
#include <bits/stdc++.h>
using namespace std;

int LIS(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    int minlen;
    for (int i = 2; i < n + 1; i++)
    {
        int j = 1;
        int minv = INT_MAX;
        while (i - j * j >= 0)
        {
            minv = min(minv, dp[i - j * j]);
            j++;
        }
        dp[i] = minv + 1;
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    int ma = LIS(n);
    cout << ma << endl;
}

//********************

#include <bits/stdc++.h>
using namespace std;

int LIS(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MAX - 1000;
    }
    int minv = INT_MAX;
    for (int i = 1; i < n + 1; i++)
    {
        minv = min(minv, 1 + LIS(n - i * i));
    }
    return minv;
}

int main()
{
    int n;
    cin >> n;

    int ma = LIS(n);
    cout << ma << endl;
}