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
    int u, v;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // adj Stored In Adj List
    vector<bool> vis(n + 1, false);
    function<bool(int)> hasCycleBFS = [&](int src)
    {
        vis[src] = true;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();
            for (auto &it : adj[node])
            {
                if (vis[it] && it != parent)
                    return true;
                else if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
            }
        }
        return false;
    };
    // Define the lambda function
    function<bool(int, int)> hasCycleDFS = [&](int node, int parent)
    {
        vis[node] = true;
        for (int it : adj[node])
        {
            if (!vis[it])
            {
                if (hasCycleDFS(it, node))
                {
                    return true;
                }
            }
            else if (it != parent)
            {
                return true; // A cycle is detected
            }
        }
        return false;
    };

    bool cycleFound = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // if (hasCycleDFS(i, -1))
            if (hasCycleBFS(i))
            {
                cycleFound = true;
                break;
            }
        }
    }

    cout << (cycleFound ? "Cycle detected!" : "No cycles.") << endl;
    return 0;
}