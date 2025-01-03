#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("../.vscode/input.txt", "r", stdin);
    freopen("../.vscode/output.txt", "w", stdout);
#endif
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    /*Spanning Tree : Tree in which we have N node and N-1 edge
    and all nodes are reachable from each other.
    MST : In which sum of weights is Minimum.*/

    // Prim's Algorithm uses a greedy approach for finding the MST.

    // Used for Optimising a Graph
    auto Prim_MST_Sum = [&](int n, vector<pair<int, int>> adj[])
    {
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int res = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [wt, node] = pq.top();
            pq.pop();
            if (vis[node])
                continue;

            vis[node] = true;
            res += wt;
            for (auto [adjNode, adjWt] : adj[node])
            {
                if (!vis[adjNode])
                    pq.push({adjWt, adjNode});
            }
        }
        return res;
    };

    auto Prim_MST = [&](int n, vector<pair<int, int>> adj[])
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, -1}); /* (Wt, node, parent) */
        vector<bool> vis(n, false);
        int res = 0;
        vector<pair<int, int>> mst;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int wt = get<0>(it);
            int node = get<1>(it);
            int par = get<2>(it);
            if (vis[node])
                continue;
            vis[node] = true;
            res += wt;
            for (auto [adjNode, adjWt] : adj[node])
            {
                if (!vis[adjNode])
                    pq.push({adjWt, adjNode, node});
            }
        }
        return res;
    };
    cout<<Prim_MST(n,adj)<<endl;
    // cout << Prim_MST_Sum(n, adj) << endl;
    return 0;
}