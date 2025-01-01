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
    vector<int> adj[n + 1];
    int u, v;
    // Adjancy list Input

    // We can use csacademy to visualize graphs
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, -1);
    function<bool(int)> isBipartite = [&](int src)
    {
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                    return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
            if (!isBipartite(i))
            {
                cout << "Not Bipartite" << endl;
                return 0;
            }
    }
    cout << "Graph is Bipartite" << endl;
    return 0;
}