#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long

vector<int> pm;
void Seive(int n)
{
    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int p = 2; p <= n; p++)
    {
        if (primes[p])
        {
            pm.push_back(p);
            for (int i = p * p; i <= n; i += p)
                primes[i] = false;
        }
    }
    return;
}

vector<ll> factorize(ll n)
{
    vector<ll> factors;
    ll i = 0;
    ll p = pm[i];
    while (p * p <= n)
    {
        if (n % p == 0)
        {
            factors.push_back(p);
            while (n % p == 0)
                n = n / p;
        }
        i++;
        p = pm[i];
    }
    if (n != 1)
        factors.push_back(n);
    return factors;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << "Prime Factors of N is" << endl;
    Seive(n);
    vector<int> factors = factorize(n);
    for (int c : factors)
        cout << c << " ";
    cout << endl;
    return 0;
}