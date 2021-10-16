#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, temp;
    cin >> n;
    int arr[n];
    unordered_map<int, int> hash1;
    unordered_map<int, int>::iterator itr;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        temp = arr[i] % k;
        if (temp == 0)
        {
            if (hash1.find(0) != hash1.end())
            {
                hash1.erase(0);
            }
            else
            {
                hash1[0] = arr[i];
            }
        }
        else if (hash1.find(k - temp) != hash1.end())
        {
            hash1.erase(k - temp);
        }
        else
        {
            hash1[temp] = arr[i];
        }
    }

    if (hash1.size() > 0)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }
}