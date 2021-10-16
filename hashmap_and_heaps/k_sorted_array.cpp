#include <bits/stdc++.h>
using namespace std;

void k_sorted(int arr[], int n, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }
    for (int j = k + 1; j < n; j++)
    {

        cout << pq.top() << endl;
        pq.pop();
        pq.push(arr[j]);
    }
    while (pq.size() > 0)
    {

        cout << pq.top() << endl;
        pq.pop();
    }
    return;
}

int main()
{

    int n, k;
    cin >> n;
    int arr[n];
    for (int j = 0; j < n; j++)
        cin >> arr[j];
    cin >> k;
    k_sorted(arr, n, k);
}
