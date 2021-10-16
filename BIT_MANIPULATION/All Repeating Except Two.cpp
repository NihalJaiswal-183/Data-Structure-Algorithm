#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mask = 0;
    for (int i = 0; i < n; i++)
    {
        mask = mask ^ arr[i];
    }
    int rsbm = mask & -mask;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & rsbm) == 0)
        {
            ans1 = ans1 ^ arr[i];
        }
        else
        {
            ans2 = ans2 ^ arr[i];
        }
    }
    if (ans1 > ans2)
    {
        cout << ans2 << endl;
        cout << ans1;
    }
    else
    {
        cout << ans1 << endl;
        cout << ans2;
    }
}