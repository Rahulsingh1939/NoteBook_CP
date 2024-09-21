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
        c += floor(v[i] / d);
    }
    return c;
}
void wise_crack()
{
    // Solution for given problem.
    cin >> n >> k;
    vector<int> a(n, 0);
    for (auto &it : a)
        cin >> it;
    double l = 0, r = 1e9, mid;
    for (int i = 0; i < 100; i++)
    {
        mid = (l + r) / 2;
        int count = noOfPiece(mid, a);
        if (count >= k)
            l = mid;
        else
            r = mid;
    }

    cout << setprecision(20);
    cout << l << '\n';

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