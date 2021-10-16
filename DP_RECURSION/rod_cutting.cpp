// #include <bits/stdc++.h>
// using namespace std;

// int rod(int a[], int n, int i, int N)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n < 0 || i > N)
//     {
//         return INT_MIN + 5;
//     }

//     int b = a[i] + rod(a, n - i, i, N);
//     int c = rod(a, n, i + 1, N);
//     return max(b, c);
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int a[n + 1];
//         for (int i = 1; i < n + 1; i++)
//             cin >> a[i];
//         int N = n;
//         int ans = rod(a, n, 1, N);
//         cout << ans << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int rod(int a[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = a[1];
    int temp;
    for (int i = 2; i < n + 1; i++)
    {
        temp = a[i];
        for (int j = i - 1; j >= 0; j--)
        {
            temp = max(temp, a[j] + dp[i - j]);
        }
        dp[i] = temp;
    }

    cout << dp[n - 1] << endl;
    return dp[n];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i < n + 1; i++)
            cin >> a[i];

        int ans = rod(a, n);
        cout << ans << endl;
    }
}

//************************************************************************
#include <bits/stdc++.h>
using namespace std;

int rod(int a[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = a[1];
    int temp;
    for (int i = 2; i < n + 1; i++)
    {
        temp = a[i];

        for (int j = i - 1; j >= 1; j--)
        {
            temp = max(temp, (a[j] + dp[i - j]));
        }
        dp[i] = temp;
    }

    return dp[n];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i < n + 1; i++)
            cin >> a[i];

        int ans = rod(a, n);
        cout << ans << endl;
    }
}