#include <bits/stdc++.h>

using namespace std;
#define ll long long
struct Congruence
{
    ll a, m;
    Congruence(ll x, ll y) : a{x}, m{y} {}
};
// Function to compute the modular inverse using the Extended Euclidean Algorithm
ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

ll mod_inv(ll a, ll m)
{
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    if (g != 1)
    {
        throw std::invalid_argument("Modular inverse does not exist");
    }
    else
    {
        return (x % m + m) % m;
    }
}

ll chinese_remainder_theorem(vector<Congruence> const &congruences)
{
    ll M = 1;
    for (auto const &congruence : congruences)
    {
        M *= congruence.m;
    }

    ll solution = 0;
    for (auto const &congruence : congruences)
    {
        ll a_i = congruence.a;
        ll M_i = M / congruence.m;
        ll N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int a, m;
    vector<Congruence> v;
    while (t--)
    {
        cin >> a >> m;
        Congruence c(a, m);
        v.push_back(c);
    }
    ll res = chinese_remainder_theorem(v);
    cout << res << endl;
    return 0;
}