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
    vector<bool> vis(n + 1, false);
    int src = 1;
    vis[src] = true;
    function<void(int)> DFS = [&](int node)
    {
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                DFS(it);
            }
        }
        cout << node << " ";
    };
    DFS(src);
    cout << endl;
    return 0;
}