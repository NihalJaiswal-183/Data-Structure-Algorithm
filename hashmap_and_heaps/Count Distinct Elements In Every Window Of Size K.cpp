#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n, k, temp;
    // cin >> n;
    // int arr[n];
    // vector<int> ans;
    unordered_map<int, int> hash1;
    unordered_map<int, int>::iterator itr;
    hash1[0]++;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cin >> k;
    // for (int i = 0; i < k; i++)
    // {
    //     hash1[arr[i]] += 1;
    // }

    // for (int i = k; i < n; i++)
    // {
    //     ans.push_back(hash1.size());
    //     hash1[arr[i]] += 1;
    //     if (hash1[arr[i - k]] == 1)
    //     {
    //         hash1.erase(arr[i - k]);
    //     }
    //     else
    //     {
    //         hash1[arr[i - k]] -= 1;
    //     }
    // }
    // ans.push_back(hash1.size());

    //for (int i = 0; i < ans.size(); i++)
    //{
        cout << hash1[0] << " ";
    //}
}
