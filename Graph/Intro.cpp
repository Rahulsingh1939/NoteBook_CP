#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
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
    vector<string> adjMat(n);
    for (int i = 0; i < n; i++)
        cin >> adjMat[i];
    // Adjacency Matrix To List Conversion
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMat[i][j] == '1')
            {

                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    return 0;
}