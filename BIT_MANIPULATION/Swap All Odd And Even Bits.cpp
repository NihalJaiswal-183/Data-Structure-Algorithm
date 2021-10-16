#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int odds = 0x55555555;
    int evens = 0xAAAAAAAA;

    odds = odds & n;
    evens = evens & n;

    odds = odds << 1;
    evens = evens >> 1;
    int ans = odds | evens;
    cout << ans;
}