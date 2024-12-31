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

    vector<string> Mat(n);
    for (int i = 0; i < n; i++)
        cin >> Mat[i];
    char iniC = Mat[1][1];
    vector<string> res = Mat;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    function<void(int, int, char)> dfs = [&](int x, int y, char newC)
    {
        res[x][y] = newC;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && Mat[nx][ny] == iniC && res[nx][ny] != newC)
            {
                dfs(nx, ny, newC);
            }
        }
    };
    dfs(1, 1, '2');
    for (string st : res)
        cout << st << endl;
    return 0;
}