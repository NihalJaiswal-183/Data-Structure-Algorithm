#include <bits/stdc++.h>
using namespace std;

bool utf_encodings(int arr[], int n)
{
    int rbytes = 0;
    for (int i = 0; i < n; i++)
    {
        if (rbytes == 0)
        {
            if ((arr[i] >> 7) == 0b0)
            {
                rbytes = 0;
            }
            if ((arr[i] >> 5) == 0b110)
            {
                rbytes = 1;
            }
            if ((arr[i] >> 4) == 0b1110)
            {
                rbytes = 2;
            }
            if ((arr[i] >> 3) == 0b11110)
            {
                rbytes = 3;
            }
        }
        else
        {
            if ((arr[i] >> 6) == 0b10)
            {
                rbytes--;
            }
            else
            {
                return false;
            }
        }
    }
    if (rbytes == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (utf_encodings(arr, n) == true)
        cout << "true";
    else
    {
        cout << "false";
    }
}