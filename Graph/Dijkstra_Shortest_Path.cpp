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
    int u, v, w;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // Graph Stored In Adj List
    vector<int> parent(n, -1);
    vector<int> dist(n, 1e9);

    auto Dijkstra = [&](int V, vector<pair<int, int>> adj[], int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            for (auto [adjNode, wt] : adj[node])
            {
                if (dist[node] + wt < dist[adjNode])
                {
                    dist[adjNode] = dist[node] + wt;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    };
    Dijkstra(n, adj, 0);
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << endl;
    int dest = 5;

    // Path to a destination = dest
    cout << "Path  to dest : " << dest << " is " << dist[dest] << endl;
    vector<int> path;
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