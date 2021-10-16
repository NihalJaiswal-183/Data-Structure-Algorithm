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

    n = s.length();
    if (k == 1)
    {

        while (i <= n - 1)
        {
            i++;
            hash[s[i]] += 1;
            if (hash.size() > 1)
            {
                i--;
                int t = hash[s[i]];
                cout << t << endl;
                ans += t * (t + 1) / 2;
                cout << ans << endl;
                hash.clear();
            }
        }

        cout << ans;
    }
    else
    {
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

            ans += i - j + 1;
        }

        cout << ans;
    }
}