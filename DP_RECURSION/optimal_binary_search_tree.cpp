#include <bits/stdc++.h>
using namespace std;

int optimalsearch(int node[], int freq[], int n)
{

    int dp[n][n];

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            int minv = INT_MAX;
            if (g == 0)
            {
                dp[i][j] = freq[i];
            }
            else if (g == 1)
            {
                dp[i][j] = min(freq[i] + 2 * freq[j], freq[j] + 2 * freq[i]);
            }

            else
            {

                for (int k = i - 1; k <= j; k++)
                {
                    if (k == i - 1)
                    {
                        minv = min(minv, dp[k + 2][j]);
                    }
                    else if (k == j)
                    {
                        minv = min(minv, dp[i][j - 1]);
                    }
                    else
                    {
                        minv = min(minv, dp[i][k] + dp[k + 2][j]);
                    }
                }
                int sum = 0;
                for (int k = i; k <= j; k++)
                    sum += freq[k];
                dp[i][j] = minv + sum;
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{

    int n;
    cin >> n;
    int node[n];
    int freq[n];
    for (int i = 0; i < n; i++)
    {
        cin >> node[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }

    cout << optimalsearch(node, freq, n) << endl;
}