#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = false;

    int j = -1;
    int rev = 0;
    for (int i = 31; i >= 0; i--)
    {
        int mask = 1 << i;
        if ((n & mask) == 0)
        {
            if (flag)
            {
                cout << "0";
                j++;
            }
        }
        else
        {
            flag = true;
            cout << "1";
            j++;

            rev = rev | (1 << j);
        }
    }

    cout << endl;
    cout << rev;
}