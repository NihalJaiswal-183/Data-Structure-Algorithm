#include <bits/stdc++.h>
using namespace std;

int totalanagram(string s)
{
    int ans0 = 0;
    int ans1 = 0;
    int right = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        if (s[right] == '1' && right < s.length())
        {
            flag = true;
            while (s[right] == '1' && right < s.length())
            {
                right++;
            }
            ans1++;
        }
        if (s[right] == '0' && right < s.length())
        {
            flag = true;
            while (s[right] == '0' && right < s.length())
            {
                right++;
            }
            ans0++;
        }
    }
    int ans = min(ans0, ans1);
    cout << ans;
}
int main()
{
    string s;
    cin >> s;
    totalanagram(s);
}