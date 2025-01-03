#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("./.vscode/input.txt", "r", stdin);
    freopen("./.vscode/output.txt", "w", stdout);
#endif
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][w] = w;
        dist[u][u] = 0;
        dist[v][v] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != 1e9 && dist[k][j] != 1e9)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return 0;
}