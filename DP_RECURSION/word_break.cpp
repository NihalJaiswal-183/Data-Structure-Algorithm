// int wordBreak(string A, vector<string> &B)
// {
//     unordered_map<string, bool> hash1;
//     for (int i = 0; i < B.size(); i++)
//     {
//         hash1[B[i]] = true;
//     }
//     int n = A.length();

//     int dp[n] = {0};

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             string str = A.substr(j, i - j + 1);

//             if (hash1.find(str) != hash1.end())
//             {
//                 if (j > 0)
//                 {

//                     dp[i] += dp[j - 1];
//                 }
//                 else
//                 {
//                     dp[i] += 1;
//                 }
//             }
//         }
//     }

//     return dp[n - 1];
// }