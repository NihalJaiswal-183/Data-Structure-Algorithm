#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b)
{

    map<char, int> m;
    for (int i = 0; i < a.length(); i++)
        m[a[i]]++;
    for (int i = 0; i < b.length(); i++)
        m[b[i]]--;
    for (auto it = m.begin(); it != m.end(); it++)
        if (it->second != 0)
            return false;
    return true;
}

int countNoOfAnagram(string a, string b)
{
    int count = 0;

    for (int i = 0; i < a.length() - b.length() + 1; i++)
    {
        if (check(a.substr(i, b.length()), b))
            count++;
    }
    return count;
}

int main()
{
    string S, C;

    cin >> S >> C;

    cout << countNoOfAnagram(S, C) << endl;

    return 0;
}
