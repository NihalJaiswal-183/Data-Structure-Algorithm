#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> graph[], int disc[], int low[], bool visited[], int parent[], bool AP[], int vertex, int o)
{
	static int ti = 1;
	visited[vertex] = true;
	disc[vertex] = low[vertex] = ti++;
	int child = 0;
	for (auto x : graph[vertex])
	{
		if (x == parent[vertex])
		{
			continue;
		}
		else if (visited[x])
		{
			low[vertex] = min(low[vertex], disc[x]);
		}
		else
		{
			parent[x] = vertex;
			child++;
			DFS(graph, disc, low, visited, parent, AP, x, o);
			low[vertex] = min(low[vertex], low[x]);
			if (vertex == o)
			{
				if (child >= 2)
				{
					AP[vertex] = true;
				}
			}
			else
			{
				if (low[x] >= disc[vertex])
					AP[vertex] = true;
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	int src, des;
	vector<int> graph[n + 1];
	for (int i = 0; i < m; i++)
	{
		cin >> src >> des;
		graph[src].push_back(des);
		graph[des].push_back(src);
	}
	int disc[n + 1], low[n + 1];
	bool visited[n + 1];
	int parent[n + 1];
	memset(parent, -1, sizeof(parent));
	memset(visited, false, sizeof(visited));
	bool AP[n + 1];
	memset(AP, false, sizeof(AP));
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
			DFS(graph, disc, low, visited, parent, AP, i, i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (AP[i] == true)
			cnt++;
	}
	cout << cnt;
}