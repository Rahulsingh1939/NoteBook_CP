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
    vector<pair<int, int>> adj[n + 1];
    int u, v, w;
    // Adjancy list Input
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    stack<int> st;
    vector<bool> vis(n, false);

    function<void(int)> dfs = [&](int node)
    {
        vis[node] = true;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
                dfs(it.first);
        }
        st.push(node);
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    vector<int> dist(n, 1e9);
    dist[0]=0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        for (auto [adjNode, wt] : adj[node])
        {
            if (dist[node] + wt < dist[adjNode])
                dist[adjNode] = dist[node] + wt;
        }
    }
    for (int it : dist)
        cout << it << " ";
    cout << endl;
    return 0;
}