#include <bits/stdc++.h>

#define ll long long
#define int long long
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define in(a)            \
    for (auto &it : (a)) \
        cin >> it;
#define out(b)           \
    for (auto &it : (b)) \
        cout << it << " ";
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define F first
#define S second
#define ld long double
#define pii pair<int, int>

const ll MOD = 1e9 + 7;
int n, k;

using namespace std;
int noOfPiece(ld d, vector<int> v)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        c += (v[i] / d);
    }
    return c;
}
void wise_crack()
{
    // Solution for given problem.
    cin >> n >> k;
    vector<int> v(n, 0);
    int mx = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mx = min<ll>(v[i], mx);
    }
    ld l = 0, h = (ld)mx;
    while (h - l > 1e-6)
    {
        ld m = (l + h) / (2.0);
        int cnt = noOfPiece(m, v);
        if (cnt >= k)
            l = m;
        else
            h = m;
    }
    cout << h << endl;
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