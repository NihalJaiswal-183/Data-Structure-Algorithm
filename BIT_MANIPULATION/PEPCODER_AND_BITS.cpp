#include <bits/stdc++.h>
using namespace std;

unsigned long long int kerighans(unsigned long long int n)
{
    unsigned long long int res = 0ULL;
    while (n > 0)
    {
        unsigned long long int rsb = n & (-n);
        n = n - rsb;
        res++;
    }
    return res;
}

unsigned long long int ncr(unsigned long long int n, unsigned long long int r)
{
    if (n < r)
    {
        return 0ULL;
    }

    unsigned long long int res = 1ULL;

    for (long long int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}
unsigned long long int solution(unsigned long long int n, unsigned long long k, unsigned long long i)
{
    if (i == 0)
    {
        return 0ULL;
    }
    unsigned long long int res = 0ULL;
    unsigned long long int mask = 1ULL << i;
    if ((mask & n) == 0)
    {
        res = solution(n, k, i - 1);
    }
    else
    {
        unsigned long long int res1 = solution(n, k - 1, i - 1);
        unsigned long long int res2 = ncr(i, k);
        res = res1 + res2;
    }
    return res;
}

int main()
{
    unsigned long long int n;
    cin >> n;

    unsigned long long int bits = kerighans(n);

    unsigned long long int count = solution(n, bits, 63);

    cout << count;
}