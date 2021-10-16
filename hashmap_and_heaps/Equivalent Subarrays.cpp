#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, ans = 0;
    cin >> n;
    int arr[n];

    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]] += 1;
    }

    k = hash.size();
    hash.clear();

    int i = -1;
    int j = 0;

    while (true)
    {
        bool flag1 = false, flag2 = false;
        while (i < n - 1)
        {
            flag1 = true;
            i++;
            hash[arr[i]] += 1;
            if (hash.size() == k)
            {

                break;
            }
        }

        while (hash.size() == k)
        {
            flag2 = true;
            ans += n - i;

            if (hash[arr[j]] == 1)
            {
                hash.erase(arr[j]);
            }
            else
            {
                hash[arr[j]] -= 1;
            }

            j++;
        }
        if (flag1 == false && flag2 == false)
        {
            break;
        }
    }
    cout << ans;
}