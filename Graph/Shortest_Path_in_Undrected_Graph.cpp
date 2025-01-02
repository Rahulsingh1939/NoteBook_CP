#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../.vscode/input.txt", "r", stdin);
    freopen("../.vscode/output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Graph Stored In Adj List
    vector<int> parent(n, -1);
    vector<int> dist(n, 1e9);
    auto BFS = [&](int V, vector<int> adj[], int src)
    {
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[it] == 1e9)
                {
                    parent[it] = node;
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
    };
    BFS(n, adj, 0);
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << endl;

    // Path to a destination = dest
    cout << "Path  to dest : " << endl;
    vector<int> path;
    int dest = 5;
    int curr = dest;
    while (curr != 0)
    {
        path.push_back(parent[curr]);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    for (int i : path)
        cout << i << " -> ";
    cout << dest << endl;
    return 0;
}