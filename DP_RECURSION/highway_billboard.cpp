#include <bits/stdc++.h>
using namespace std;

int maxbill(int n, int dis[], int price[], int i, int prev, int t)
{
    if (i == n)
    {
        return 0;
    }
    if (dis[i] - prev <= t)
    {
        return maxbill(n, dis, price, i + 1, prev, t);
    }
    else
    {
        return max(price[i] + maxbill(n, dis, price, i + 1, dis[i], t), maxbill(n, dis, price, i + 1, prev, t));
    }
}

int main()
{
    int m, n, t;
    cin >> m >> n;
    int dis[n], price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dis[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cin >> t;
    cout << maxbill(n, dis, price, 0, 0, t);
}

//********************************************
//o(n*n)soln
#include <bits/stdc++.h>
using namespace std;

int maxbill(int n, int dis[], int price[], int t)
{

    int dp[n];
    dp[0] = price[0];
    int temp;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        temp = 0;
        for (int j = 0; j < i; j++)
        {
            if (dis[i] - dis[j] > t)
            {
                temp = max(temp, dp[j]);
            }
        }
        dp[i] = price[i] + temp;
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, t;
    cin >> m >> n;
    int dis[n], price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dis[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cin >> t;
    cout << maxbill(n, dis, price, t);
}
//***************************************************
//o(m) soln with o(n)extra space
#include <bits/stdc++.h>
using namespace std;

int maxbill(int m, int n, int dis[], int price[], int t)
{

    int dp[m + 1];
    dp[0] = 0;
    int temp = 0;
    int ans = 0;
    unordered_map<int, int> hash1;
    for (int i = 0; i < n; i++)
    {
        hash1[dis[i]] = price[i];
    }
    for (int i = 1; i < m + 1; i++)
    {
        if (hash1.find(i) != hash1.end())
        {
            if (i >= t + 1)
            {
                dp[i] = max(dp[i - 1], hash1[i] + dp[i - t - 1]);
            }
            else
            {
                dp[i] = hash1[i];
            }
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    return dp[m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, t;
    cin >> m >> n;
    int dis[n], price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dis[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cin >> t;
    cout << maxbill(m, n, dis, price, t);
}