#include <bits/stdc++.h>
using namespace std;

int bs = 0;

vector<int> blocks, arr;

void update(int idx, int val)
{
    blocks[idx / bs] = blocks[idx / bs] - arr[idx] + val;
    arr[idx] = val;
}
int query(int li, int ri)
{
    int sum = 0;
    while (li % bs != 0 && li <= ri)
    {
        sum + arr[li++];
    }
    while (li + bs <= ri)
    {
        sum += blocks[li / bs];
        li += bs;
    }
    while (li <= ri)
    {
        sum += arr[li++];
    }
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    bs = (int)sqrt(n) + 1;
    blocks.resize(bs + 1, 0);
    arr.resize(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
        blocks[i / bs] += a;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r);
        }
        else
        {
            int idx, val;
            cin >> idx >> val;
            update(idx, val);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}