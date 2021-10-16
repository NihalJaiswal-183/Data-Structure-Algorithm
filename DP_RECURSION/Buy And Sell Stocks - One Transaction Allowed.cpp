#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans[n];
    int minv = INT_MAX;
    int maxv = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            minv = min(minv, arr[j]);
        }
        if (minv >= arr[i])
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = arr[i] - minv;
        }
        maxv = max(maxv, ans[i]);
    }
    cout << maxv;
}