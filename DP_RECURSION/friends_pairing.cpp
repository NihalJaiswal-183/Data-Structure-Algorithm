#include <bits/stdc++.h>
using namespace std;
vector<int> fin;
void fpair(int i, int t, string anf, int path[])
{

    if (i > t)
    {
        cout << anf << endl;
        fin.push_back(1);
        return;
    }
    if (path[i] == 1)
        fpair(i + 1, t, anf, path);
    else
    {

        path[i] = 1;
        fpair(i + 1, t, anf + "{" + to_string(i) + "}", path);
        for (int j = i + 1; j <= t; j++)
        {
            if (path[j] == 0)
            {
                path[j] = 1;
                fpair(i + 1, t, anf + "{" + to_string(i) + "," + to_string(j) + "}", path);
                path[j] = 0;
            }
        }

        path[i] = 0;
    }
}

int main()
{
    int t;
    cin >> t;
    int path[t + 1];
    string anf = "";

    fpair(1, t, anf, path);
    cout << fin.size();
}
//************************************************

// int countFriendsPairings(int n) 
//     { 
//     long long int dp[n+1];
//      dp[1]=1;
//      dp[2]=2;
    
//     for(int i=3;i<=n;i++){
//         dp[i]=(dp[i-1]%mod+((i-1)%mod*dp[i-2]%mod)%mod)%mod;
//     }
//     return dp[n];
//     }