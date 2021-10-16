#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n, k;
    cin >> k;
    n = s.length() - 1;
    unordered_map<char, int> hashbig;
    unordered_map<char, int> hashsmall;
    int ib = -1, is = -1, j = -1, ans = 0;
    if (k == 1)
    {

        while (ib <= n)
        {
            ib++;
            hashsmall[s[ib]] += 1;
            if (hashsmall.size() > 1)
            {
                ib--;
                int t = hashsmall[s[ib]];
                ans += t * (t + 1) / 2;

                hashsmall.clear();
            }
            else if (ib == n)
            {
                int t = hashsmall[s[ib]];
                ans += t * (t + 1) / 2;
                break;
            }
        }

        cout << ans;
    }
    else
    {
        while (true)
        {
            bool flag1 = false, flag2 = false, flag3 = false;
            while (ib < n)
            {
                flag1 = true;
                ib++;
                hashbig[s[ib]] += 1;
                if (hashbig.size() == k + 1)
                {
                    hashbig.erase(s[ib]);
                    ib--;
                    break;
                }
            }
            while (is < n)
            {
                flag2 = true;
                is++;
                hashsmall[s[is]] += 1;
                if (hashsmall.size() == k)
                {
                    hashsmall.erase(s[is]);
                    is--;
                    break;
                }
            }
            while (j < is)
            {
                flag3 = true;
                j++;
                if (hashsmall.size() == k - 1 && hashbig.size() == k)
                {
                    ans += ib - is;
                }
                int key = s[j];
                if (hashbig[key] == 1)
                {
                    hashbig.erase(key);
                }
                else
                {
                    hashbig[key] -= 1;
                }
                if (hashsmall[key] == 1)
                {
                    hashsmall.erase(key);
                }
                else
                {
                    hashsmall[key] -= 1;
                }
                if (hashsmall.size() < k - 1 || hashbig.size() < k)
                {
                    break;
                }
            }
            if (flag1 == false && flag2 == false && flag3 == false)
            {
                break;
            }
        }

        cout << ans;
    }
}