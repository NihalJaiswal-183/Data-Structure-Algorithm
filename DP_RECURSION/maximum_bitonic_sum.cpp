#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(int a[], int n)
{

    int dplis[n];
    dplis[0] = a[0];
    ;
    int maxsum;
    for (int i = 1; i < n; i++)
    {
        maxsum = 0;
        for (int j = i - 1; j >= 0; j--)
        {

            if (a[j] < a[i])
                maxsum = max(maxsum, dplis[j]);
        }
        dplis[i] = maxsum + a[i];
    }
    int dplds[n];

    dplds[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxsum = 0;
        for (int j = i + 1; j < n; j++)
        {

            if (a[j] < a[i])
                maxsum = max(maxsum, dplds[j]);
        }
        dplds[i] = maxsum + a[i];
    }
    int maxv = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (maxv < (dplds[i] + dplis[i] - a[i]))
        {
            maxv = dplds[i] + dplis[i] - a[i];
        }
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = LongestBitonicSequence(a, n);
        cout << ans << endl;
    }
}