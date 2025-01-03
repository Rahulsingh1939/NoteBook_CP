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

    // Storing edges as a list of tuples
    vector<tuple<int, int, int>> edges;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Bellman-Ford Algorithm
    auto BellMonFord = [&](int n, vector<tuple<int, int, int>> &edges, int src)
    {
        vector<int> dist(n, 1e9); // Initialize distances with "infinity"
        dist[src] = 0;

        // Relax all edges n-1 times
        for (int i = 0; i < n - 1; i++)
        {
            for (auto edge : edges)
            {
                int u = get<0>(edge);
                int v = get<1>(edge);
                int wt = get<2>(edge);

                if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycle
        for (auto edge : edges)
        {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int wt = get<2>(edge);

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                cout << "Negative weight cycle detected\n";
                return;
            }
        }

        // Print distances
        for (int i = 0; i < n; i++)
        {
            cout << "Distance to node " << i << ": " << (dist[i] == 1e9 ? "INF" : to_string(dist[i])) << "\n";
        }
    };

    // Call Bellman-Ford from source node 0
    BellMonFord(n, edges, 0);

    return 0;
}
