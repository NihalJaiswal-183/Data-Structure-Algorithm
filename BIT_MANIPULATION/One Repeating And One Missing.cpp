#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[2 * n];
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int j = 1;
    for (int i = n; i < 2 * n; i++)
    {
        arr[i] = j;
        j++;
    }
    int mask = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        mask = mask ^ arr[i];
    }
    int rsbm = mask & -mask;

    for (int i = 0; i < 2 * n; i++)
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
    int count = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (ans1 == arr[i])
            count++;
    }
    if (count == 1)
    {
        cout << "Missing Number -> " << ans1 << endl;
        cout << "Repeating Number -> " << ans2;
    }
    else
    {
        cout << "Missing Number -> " << ans2 << endl;
        cout << "Repeating Number -> " << ans1;
    }
}