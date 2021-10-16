#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    int count = 0;
    while (n != 1)
    {
        if ((n & 3) == 1)
        {
            n = n - 1;
        }
        else if ((n & 3) == 3)
        {
            n = n + 1;
        }
        else if (n == 3)
        {
            n = 2;
        }
        else
        {
            n = n / 2;
        }
        count++;
    }
    cout << count;
}