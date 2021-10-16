#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int n;
    cin >> n;
    unsigned long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unsigned long long int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        long long int count0 = 0;
        long long int count1 = 0;
        for (int j = 0; j < n; j++)
        {
            if ((arr[j] & (1 << i)) == 0)
            {
                count0++;
            }
            else
            {
                count1++;
            }
        }
        ans += count0 * count1 * 2;
    }
    cout << ans;
}