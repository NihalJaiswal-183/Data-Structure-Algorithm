#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n, k, ans = 0;
    cin >> k;

    unordered_map<char, int> hash;

    int i = -1;
    int j = 0;
    int len = INT_MIN;
    n = s.length();

    while (i < n - 1)
    {

        i++;
        hash[s[i]] += 1;

        while (hash.size() > k && j < i)
        {

            if (hash[s[j]] == 1)
            {
                hash.erase(s[j]);
            }
            else
            {
                hash[s[j]] -= 1;
            }
            j++;
        }

        len = max(len, i - j + 1);
    }
    cout << len;
}