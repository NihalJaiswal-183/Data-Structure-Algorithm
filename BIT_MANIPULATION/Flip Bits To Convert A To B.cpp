#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    int k = n1 ^ n2;
    int res = 0;
    while (k > 0)
    {
        int rsb = k & (-k);
        k = k - rsb;
        res++;
    }
    cout << res;
}