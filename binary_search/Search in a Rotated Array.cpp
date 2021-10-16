#include <bits/stdc++.h>
using namespace std;

long long int binary_search(int arr[], int start, int end, int key)
{
    long long int low = start;
    long long int high = end;

    while (low < high)
    {
        long long int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return -1;
}
long long int find_pivot(int arr[], int n)
{
    long long int low = 0;
    long long int high = n;

    while (low < high)
    {
        long long int mid = low + (high - low) / 2;
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
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
        {
            cin >> arr[i];
        }
        int k = find_pivot(arr, n - 1);
        long long int key;
        cin >> key;
        if (arr[k] == key)
        {
            cout << k << endl;
        }
        else if (k == 0)
        {
            int d = binary_search(arr, 0, n, key);
            cout << d << endl;
        }
        else if (key >= arr[0])
        {
            int a = binary_search(arr, 0, k, key);
            cout << a << endl;
        }
        else
        {
            int c = binary_search(arr, k + 1, n, key);
            cout << c << endl;
        }
    }
}