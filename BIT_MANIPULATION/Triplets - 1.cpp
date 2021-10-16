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
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xorx = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            xorx ^= arr[j];
            if (xorx == 0)
            {
                count += j - i;
            }
        }
    }
    cout << count;
}