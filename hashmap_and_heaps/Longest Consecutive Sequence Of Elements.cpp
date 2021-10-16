#include <bits/stdc++.h>
using namespace std;

void getseq(int n, int arr[])
{
    unordered_map<int, bool> hash1;
    unordered_map<int, bool>::iterator itr;
    for (int i = 0; i < n; i++)
    {
        hash1[arr[i]] = true;
    }
    for (itr = hash1.begin(); itr != hash1.end(); ++itr)
    {
        if (hash1.find((*itr).first - 1) != hash1.end())
        {
            (*itr).second = false;
        }
    }
    int maxsize = 0;
    int startpoint;
    int size = 0;
    int currvalue;
    for (itr = hash1.begin(); itr != hash1.end(); ++itr)
    {

        if ((*itr).second == true)
        {
            size = 0;
            currvalue = (*itr).first;
            while (hash1.find(currvalue) != hash1.end())
            {
                currvalue += 1;
                size++;
            }

            if (size > maxsize)
            {
                maxsize = size;
                startpoint = (*itr).first;
            }
            if (size == maxsize)
            {
                if (startpoint > (*itr).first)
                    startpoint = (*itr).first;
            }
        }
    }

    for (int j = 0; j < maxsize; j++)
    {
        cout << startpoint + j << endl;
    }
    return;
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int j = 0; j < n; j++)
        cin >> arr[j];
    getseq(n, arr);
}
