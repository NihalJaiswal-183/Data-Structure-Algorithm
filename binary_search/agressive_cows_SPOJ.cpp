#include <bits/stdc++.h>
using namespace std;

bool isvalid(int arr[], int n, int c, int dis)
{
    c = c - 1;
    int prev = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[prev] >= dis)
        {
            c--;
            prev = i;
        }
        if (c == 0)
        {
            return true;
        }
    }
    return false;
}

int search_space(int arr[],int n,int c)
{

int start=0;
int end=arr[n-1]-arr[0];
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isvalid(arr, n, c, mid) == true)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid-1;
        }
    }
    return res;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int c;
        cin >> c;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int a = search_space(arr,n,c);
        cout << a << endl;
    }

    return 0;
}