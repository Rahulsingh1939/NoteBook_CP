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
    vector<int> diffArray(t, 0);
    // Difference Array Method Method
    // Range Query Operation - O(1)
    // Point Update Method - O(N)
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }
    int q;
    cin >> q;
    // For every Query, Given is L,R,Val
    // Type of operation
    // Given L,R,Val increase all values in [l,r] by Val
    // Print Final Array After Q Operations.
    while (q--)
    {
        int l, r, val;
        cin >> l >> r >> val;
        diffArray[l - 1] += val;
        if (r < t)
            diffArray[r] += -1 * val;
    }
    int s = 0;
    for (int i = 0; i < t; i++)
    {
        s += diffArray[i];
        cout << v[i] + s << " ";
    }
    cout << endl;
    return 0;
}