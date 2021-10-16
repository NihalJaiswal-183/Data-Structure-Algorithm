// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool topoSort(int V, vector<int> adj[])
    {
        // code here

        int indeg[V];
        for (int i = 0; i < V; i++)
            indeg[i] = 0;
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
            {
                indeg[x]++;
            }
        }

        queue<int> topo;
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
            {
                count++;
                topo.push(i);
            }
        }

        vector<int> ans;
        while (topo.size() > 0)
        {
            int rem = topo.front();
            topo.pop();
            ans.push_back(rem);
            for (auto x : adj[rem])
            {
                indeg[x]--;
                if (indeg[x] == 0)
                {
                    count++;
                    topo.push(x);
                }
            }
        }
        if (count == V)
            return false;
        else
            return true;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        return topoSort(V, adj);
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends