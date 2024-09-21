#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
int n, k;

using namespace std;
bool Check(int mid, vector<int> v)
{
    // Check for Statement
    return true;
}
void wise_crack()
{
    // Solution for given problem.
    cin >> n >> k;
    vector<int> v(n, 0);
    int mx = 1e9;
    int l = 0, h = mx;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (Check(m, v))
            l = m + 1;
        else
            h = m - 1;
    }
    cout << h << l << endl;
    return;
}
signed main()
{
    // Coder --> binary_Rahul
    // College --> NIT Raipur
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // For T number of test cases.
    int t = 1;
    while (t--)
    {
        wise_crack();
    }
    return 0;
}