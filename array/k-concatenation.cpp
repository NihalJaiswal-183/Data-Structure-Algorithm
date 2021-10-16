#include <bits/stdc++.h>
using namespace std;

int kadanes(int arr[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + arr[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

int kConcatenation(int n, int k, int arr[])
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	int m = 2 * n;
	int a[m];

	for (int i = 0; i < m; i++)
	{
		if (i < n)
		{
			a[i] = arr[i];
		}
		else
		{
			a[i] = arr[i - n];
		}
	}
	int ans = kadanes(arr, n);
	if (k == 1)
	{
		return ans;
	}
	else if (sum == ans)
	{
		return sum * k;
	}
	else
	{
		int ans2 = kadanes(a, m);
		if (ans2 > sum * k)
		{
			return ans2;
		}
		else
		{
			return sum * k;
		}
	}
}

int main()
{

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int k;
	cin >> k;

	int ma = kConcatenation(n, k, arr);
	cout << ma << endl;
}