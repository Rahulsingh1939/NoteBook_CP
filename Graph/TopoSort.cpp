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
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<bool> vis(n, false);

    function<void(int)> dfs = [&](int node)
    {
        vis[node] = true;
        for (int it : adj[node])
        {
            if (!vis[it])
                dfs(it);
        }
        st.push(node);
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}