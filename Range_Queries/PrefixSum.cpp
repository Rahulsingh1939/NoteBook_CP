#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<int> v(t);
    vector<int> preSum(t, 0);
    ll s = 0;
    // Prefix Sum Method
    // Range Query Operation - O(1)
    //  Point Update Method - O(N)
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
        s += v[i];
        preSum[i] = s;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int x = 0;
        if (l - 1 > 0)
            x = preSum[l - 2];
        cout << preSum[r - 1] - x << endl;
    }
    return 0;
}