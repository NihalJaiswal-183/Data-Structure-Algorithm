#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string src, des;
    unordered_map<string, bool> hash1;
    unordered_map<string, string> hash2;
    unordered_map<string, bool>::iterator itr;
    unordered_map<string, string>::iterator it;
    for (int i = 0; i < n; i++)
    {
        cin >> src >> des;
        hash2[src] = des;
        if (hash1.find(src) != hash1.end())
        {
            hash1[des] = false;
        }
        else
        {
            hash1[src] = true;
            hash1[des] = false;
        }
    }
    src = "";
    for (itr = hash1.begin(); itr != hash1.end(); ++itr)
    {
        if ((*itr).second == true)
        {
            src = (*itr).first;
            break;
        }
    }

    while (true)
    {
        if (hash2.find(src) != hash2.end())
        {
            cout << src << " -> ";
            src = hash2[src];
        }
        else
        {
            cout << src << ".";
            break;
        }
    }
}