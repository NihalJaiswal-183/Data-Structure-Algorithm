class Solution
{
public:
    int minCost(string s, vector<int> &cost)
    {
        int prefix[s.length()];
        memset(prefix, 0, sizeof(prefix));
        prefix[0] = cost[0];
        for (int i = 1; i < s.length(); i++)
        {
            prefix[i] += prefix[i - 1] + cost[i];
        }
        int ans = 0;
        int idx = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            int mv = INT_MIN;
            if (s[i] == s[i + 1])
            {
                idx = i;
                bool flag = true;
                while (flag && i < s.size())
                {
                    mv = max(mv, cost[i]);
                    mv = max(mv, cost[i + 1]);
                    i++;
                    if (s[i] != s[i + 1])
                    {
                        flag = false;
                    }
                }
                if (idx > 0)
                    ans += prefix[i] - prefix[idx - 1] - mv;
                else
                    ans += prefix[i] - mv;
            }
        }
        return ans;
    }
};