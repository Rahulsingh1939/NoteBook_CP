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
    auto BFS = [&](int V, vector<int> adj[], int src)
    {
        vector<vector<int>> res;
        vector<bool> vis(V + 1, false);
        vis[src] = true;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> lvl;
            for (int s = 0; s < size; s++)
            {
                int node = q.front();
                lvl.push_back(node);
                q.pop();
                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
            res.push_back(lvl);
        }
        return res;
    };

    vector<vector<int>> res = BFS(n, adj, 1);
    for (auto it : res)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}