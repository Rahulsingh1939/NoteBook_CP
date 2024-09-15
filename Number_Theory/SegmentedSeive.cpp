#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<char> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // Print Primes betweeb 1e8 and 1e9
    ll tt;
    cin >> tt;
    while (tt--)
    {
        ll a, b;
        cin >> a >> b;
        vector<char> res = segmentedSieve(a, b);
        // cout << "No Of Primes Betweeb 1e8 and 1e9 is : " << endl;
        // for (char c : res)
        //     cout << c;
        for (ll i = a; i <= b; i++)
            if (res[i - a])
                cout << i << endl;
    }
    return 0;
}