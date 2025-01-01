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
    function<vector<int>()> Khan_Topo = [&]()
    {
        vector<int> inD(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int it : adj[i])
                inD[it]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inD[i] == 0)
                q.push(i);
        }

        vector<int> res;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int it : adj[node])
            {
                inD[it]--;
                if (inD[it] == 0)
                    q.push(it);
            }
        }
        return res;
    };
    vector<int> ans = Khan_Topo();
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}