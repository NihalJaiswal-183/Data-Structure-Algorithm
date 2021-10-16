#include <bits/stdc++.h>
using namespace std;
int maxlen = INT_MIN;

void LIS(int arr[], int n, int prev, int l, int i)
{
    if (n < i || arr[i] < prev)
    {
        if (maxlen < l)
        {
            maxlen = l;
        }
        return;
    }

    LIS(arr, n, arr[i], l + 1, i + 1);
    LIS(arr, n, prev, l, i + 1);
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
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        LIS(arr, n, INT_MIN, 0, 0);
        cout << maxlen;
    }
}

//**************************************************************************

#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n)
{
    int dp[n];
    dp[0] = 1;
    int maxlen;
    for (int i = 1; i < n; i++)
    {
        maxlen = 0;
        for (int j = i - 1; j >= 0; j--)
        {

            if (arr[j] < arr[i])
                maxlen = max(maxlen, dp[j]);
        }
        dp[i] = maxlen + 1;
    }
    int maxv = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxv = max(maxv, dp[i]);
    }
    return maxv;
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
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ma = LIS(arr, n);
        cout << ma << endl;
    }
}
//************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int len, maxi, maxv;
    string psf;

public:
    Pair(string psf, int len, int maxi, int maxv)
    {
        this->psf = psf;
        this->len = len;
        this->maxi = maxi;
        this->maxv = maxv;
    }
};

int LIS(int arr[], int n)
{
    int dp[n];
    dp[0] = 1;
    int maxlen;
    for (int i = 1; i < n; i++)
    {
        maxlen = 0;
        for (int j = i - 1; j >= 0; j--)
        {

            if (arr[j] < arr[i])
                maxlen = max(maxlen, dp[j]);
        }
        dp[i] = maxlen + 1;
    }
    int maxl = 0;
    int maxindex;
    for (int i = 0; i < n; i++)
    {
        if (maxl < dp[i])
        {
            maxl = dp[i];
            maxindex = i;
        }
    }
    cout << maxl << endl;

    queue<Pair> bfs;
    bfs.push(Pair(to_string(arr[maxindex]) + "", maxl, maxindex, arr[maxindex]));
    while (bfs.size() > 0)
    {
        Pair rem = bfs.front();
        bfs.pop();
        if (rem.len == 1)
        {
            cout << rem.psf << endl;
        }
        for (int i = 0; i < rem.maxi; i++)
        {
            if (dp[i] == rem.len - 1 && rem.maxv > arr[i])
            {
                bfs.push(Pair(to_string(arr[i]) + " -> " + rem.psf, dp[i], i, arr[i]));
            }
        }
    }
    return;
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    LIS(arr, n);
    //cout<<ma<<endl;
}