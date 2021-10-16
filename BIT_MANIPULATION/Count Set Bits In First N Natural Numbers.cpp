#include <bits/stdc++.h>
using namespace std;

int maxpowof2(int n)
{
    int x = 0;
    while ((1 << x) <= n)
    {
        x++;
    }
    return x - 1;
}
int solution(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int x = maxpowof2(n);
    int a = x * (1 << (x - 1));
    int b = n - (1 << x) + 1;
    int rem = b - 1;
    int c = solution(rem);
    int ans = a + b + c;
    return ans;
}

int main()
{
    unsigned long long int n;
    cin >> n;

    cout << solution(n);
}