#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1;
    cin >> n1;

    int k = n1;
    int res = 0;
    while (k > 0)
    {
        int rsb = k & (-k);
        k = k - rsb;
        res++;
    }
    if (res == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}