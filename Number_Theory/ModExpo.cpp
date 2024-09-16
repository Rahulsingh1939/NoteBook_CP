#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1000000007;
ll mod_exp(ll base, ll exp, ll mod)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    //A to power B modulo MOD
    cout << mod_exp(a, b, MOD);
    return 0;
}