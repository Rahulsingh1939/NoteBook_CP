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
    vector<vector<int>> adj(n, vector<int>(n, 0));
    int u, v;
    // Adjancy list Input

    // We can use csacademy to visualize graphs
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int k = 3;
    vector<int> color(n, -1);
    function<bool(int, int)> isSafe = [&](int node, int col)
    {
        for (int k = 0; k < n; k++)
        {
            if (k != node && adj[k][node] == 1 && color[k] == col)
                return false;
        }
        return true;
    };
    // Check If a graph can be colored by K Colors
    function<bool(int)> canColor = [&](int node)
    {
        if (node == n)
            return true;
        for (int i = 1; i <= k; i++)
        {
            if (isSafe(node, i))
            {
                color[node] = i;
                if (canColor(node + 1))
                    return true;
                color[node] = -1;
            }
        }
        return false;
    };
    if (canColor(0))
        cout << "Can Color" << endl;
    else
        cout << "No Color Possible" << endl;
    return 0;
}