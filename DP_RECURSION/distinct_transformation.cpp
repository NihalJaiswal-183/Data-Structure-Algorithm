#include <bits/stdc++.h>
using namespace std;

int distinctTransformation(string src, string target, int i, string asf)
{

    if (asf == target && i == src.length())
    {
        return 1;
    }
    if (i > src.length())
    {
        return 0;
    }

    int a, b = 0;
    a = distinctTransformation(src, target, i + 1, asf + src[i]);
    b = distinctTransformation(src, target, i + 1, asf);

    return a + b;
}

int main()
{
    string src, target;
    cin >> src >> target;
    int dp[src.length()];
    cout << distinctTransformation(src, target, 0, "");
}

//***********************************memozize
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int distinctTransformation(string src, string target, int i, int j)
{

    if (i == src.length())
    {
        if (j == target.length())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (i == src.length())
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int tw;
    if (src[i] != target[j])
    {
        tw = distinctTransformation(src, target, i + 1, j);
    }
    else
    {

        int a = distinctTransformation(src, target, i + 1, j + 1);
        int b = distinctTransformation(src, target, i + 1, j);
        tw = a + b;
    }
    dp[i][j] = tw;
    return tw;
}

int main()
{
    string src, target;
    cin >> src >> target;

    memset(dp, -1, sizeof(dp));
    cout << distinctTransformation(src, target, 0, 0);
}
//******************************dp top down
#include <bits/stdc++.h>
using namespace std;

int distinctTransformation(string src, string target)
{

    int n = target.length();
    int m = src.length();

    int dp[n + 1][m + 1];

    for (int i = 0; i < m + 1; i++)
    {
        dp[n][i] = 1;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][m] = 0;
    }

    dp[n][m] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (src[j] == target[i])
            {
                dp[i][j] = dp[i + 1][j + 1] + dp[i][j + 1];
            }
            else
            {
                dp[i][j] = dp[i][j + 1];
            }
        }
    }
    return dp[0][0];
}

int main()
{
    string src, target;
    cin >> src >> target;

    cout << distinctTransformation(src, target);
}