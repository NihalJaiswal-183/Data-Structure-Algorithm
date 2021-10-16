#include <bits/stdc++.h>
using namespace std;
// we can usr rsb in finding the no of setbits by using the eqn no=no-rsb;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int rmb = n & -n;
        if (rmb == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = log2(rmb) + 1;
        cout << ans << endl;
    }
    return 0;
}