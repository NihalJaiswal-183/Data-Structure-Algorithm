#include <bits/stdc++.h>
using namespace std;
int counter = 0;

void partitionsubset(int k, vector<vector<int>> &ans, int i, int nsf, int n)
{

    if (i > n)
    {

        if (k == nsf)
        {
            counter++;
            cout << counter << ".";
            cout << "{";

            for (int i = 0; i < ans.size(); i++)
            {

                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j];
                    if (j != ans[i].size() - 1)
                        cout << ",";
                }

                cout << "|";
            }
            cout << "}";

            cout << endl;
        }
        return;
    }

    for (int j = 0; j < ans.size(); j++)
    {
        if (ans[j].size() > 0)
        {
            ans[j].push_back(i);
            partitionsubset(k, ans, i + 1, nsf, n);
            ans[j].pop_back();
        }
        else
        {
            ans[j].push_back(i);
            partitionsubset(k, ans, i + 1, nsf + 1, n);
            ans[j].pop_back();
            break;
        }
    }
}

int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> v;
    vector<vector<int>> ans;
    for (int i = 0; i < 3; i++)
    {
        ans.push_back(v);
    }
    partitionsubset(2, ans, 1, 0, 3);
}
//***********************************************************************************************************************************************************

#include <iostream>
using namespace std;

int countP(int n, int k)
{

    if (n == 0 || k == 0 || k > n)
        return 0;
    if (k == 1 || k == n)
        return 1;

    return k * countP(n - 1, k) + countP(n - 1, k - 1);
}

int main()
{
    cout << countP(3, 2);
    return 0;
}
//***********************************************************************************************************************************************************
#include <iostream>
using namespace std;

int countP(int n, int k)
{
    int dp[k + 1][n + 1];
    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i >= 0 && j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j > 0)
            {
                dp[i][j] = 0;
            }
            else if (i > i)
            {
                dp[i][j] = 0;
            }
            else if (j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + i * dp[i][j - 1];
            }
        }
    }

    return dp[k][n];
}

int main()
{
    cout << countP(3, 2);
    return 0;
}