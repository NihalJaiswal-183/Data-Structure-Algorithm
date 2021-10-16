#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> str;
    string temp;
    for (int i = 0; i < (1 << str.length()); i++)
    {
        int count = 0;
        temp = "";
        for (int j = 0; j < str.length(); j++)
        {
            int bit = str.length() - 1 - j;
            int mask = 1 << bit;
            if ((i & mask) == 0)
            {
                if (count == 0)
                {
                    temp = temp + str[j];
                }
                else
                {
                    temp = temp + to_string(count) + str[j];
                    count = 0;
                }
            }
            else
            {
                count++;
            }
        }
        if (count > 0)
        {
            temp += to_string(count);
        }
        cout << temp << endl;
    }
}