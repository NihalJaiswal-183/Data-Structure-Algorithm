#include <bits/stdc++.h>
using namespace std;
int countways(int n, int m)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == m)
    {
        return 2;
    }
    if (n < m)
    {
        return 1;
    }
    return countways(n - 1, m) + countways(n - m, m);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int ans = countways(n, m);
        cout << ans << endl;
    }
}
//***************************************************************************************************************************************************************
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int countWays(int n, int m)
{

    int count[n + 1];
    count[0] = 0;

    for (int i = 1; i <= n; i++)
    {

        if (i > m)
            count[i] = (count[i - 1] % mod + count[i - m] % mod) % mod;

        else if (i < m || i == 1)
            count[i] = 1;

        else
            count[i] = 2;
    }

    return count[n];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int ans = countWays(n, m);
        cout << ans << endl;
    }
}