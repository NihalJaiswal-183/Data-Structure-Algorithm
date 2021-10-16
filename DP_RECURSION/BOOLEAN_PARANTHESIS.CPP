#include <bits/stdc++.h>
using namespace std;

int F(string str, int i, int j);
int T(string str, int i, int j)
{
    if (i == j)
    {
        if (str[i] == 'T')
            return 1;
        else
            return 0;
    }
    int a = 0;
    for (int k = i; k <= j - 2; k = k + 2)
    {
        if (str[k + 1] == '&')
        {
            a += T(str, i, k) * T(str, k + 2, j);
        }
        else if (str[k + 1] == '|')
        {
            a += T(str, i, k) * T(str, k + 2, j) + T(str, i, k) * F(str, k + 2, j) + F(str, i, k) * T(str, k + 2, j);
        }
        else
        {
            a += F(str, i, k) * T(str, k + 2, j) + T(str, i, k) * F(str, k + 2, j);
        }
    }
    return a;
}
int F(string str, int i, int j)
{
    if (i == j)
    {
        if (str[i] == 'T')
            return 0;
        else
            return 1;
    }
    int a = 0;
    for (int k = i; k <= j - 2; k = k + 2)
    {
        if (str[k + 1] == '&')
        {
            a += T(str, i, k) * F(str, k + 2, j) + F(str, i, k) * T(str, k + 2, j) + F(str, i, k) * F(str, k + 2, j);
        }
        else if (str[k + 1] == '|')
        {
            a += F(str, i, k) * F(str, k + 2, j);
        }
        else
        {
            a += T(str, i, k) * T(str, k + 2, j) + F(str, i, k) * F(str, k + 2, j);
        }
    }
    return a;
}

int main()
{

    int n;
    cin >> n;
    string str;
    cin >> str;

    cout << T(str, 0, n - 1) << endl;
}
