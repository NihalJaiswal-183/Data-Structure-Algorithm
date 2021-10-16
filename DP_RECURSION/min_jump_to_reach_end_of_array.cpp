#include <bits/stdc++.h>
using namespace std;

int solve(int i, int arr[], int n)
{
    // if (i >= n)
    //     return 9999; //if you return INT_MAX then take care of integer overflow condition while adding 1
    if (i >=(n - 1))
        return 0;
    int minvalue = INT_MAX;
    for (int j = i + 1; j <= arr[i] + i; j++)
    {

        minvalue = min(minvalue, 1 + solve(j, arr, n));
    }
    return minvalue;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        cout << solve(0, arr, n) << endl;
    }
    return 0;
}
//***********************************************************************
/*#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{

    int dp[n];
    dp[n - 1] = 0;
    for (int j = n - 2; j >= 0; j--)
    {
        if (arr[j] == 0)
            dp[j] = INT_MAX;

        else if (arr[j] + j >= n - 1)
            dp[j] = 1;
        else
        {
            int minv = INT_MAX;
            for (int i = j + 1; i <= j + arr[j]; i++)
            {
                minv = min(minv, dp[i]);
            }
            if (minv != INT_MAX)
            {
                dp[j] = minv + 1;
            }
            else
            {
                dp[j] = INT_MAX;
            }
        }
    }
    return dp[0];
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        int ans = solve(arr, n);
        if (ans != INT_MAX)
            cout << ans << endl;
        else
            cout << "-1" << endl;
    }
}
*/