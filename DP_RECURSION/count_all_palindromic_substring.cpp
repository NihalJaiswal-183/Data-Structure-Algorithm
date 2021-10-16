#include <iostream>
using namespace std;

int solve(string str)
{
    int n = str.length();
    bool dp[n][n] = {false};

    int count = 0;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                if (str[i] == str[j])
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }

            else
            {
                if (str[i] == str[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            if (dp[i][j] & g != 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;

        cout << solve(str) << endl;
    }
    return 0;
}