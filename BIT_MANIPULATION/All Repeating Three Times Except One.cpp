#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int tn = INT_MAX, tnp1 = 0, tnp2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int cwtn = tn & arr[i];
        int cwtp1 = tnp1 & arr[i];
        int cwtp2 = tnp2 & arr[i];

        tnp1 = tnp1 | cwtn;
        tn = tn & (~cwtn);

        tnp2 = tnp2 | cwtp1;
        tnp1 = tnp1 & (~cwtp1);

        tn = tn | cwtp2;
        tnp2 = tnp2 & (~cwtp2);
    }
    cout << tnp1;
}