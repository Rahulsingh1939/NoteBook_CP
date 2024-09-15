#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<bool> Seive(int n)
{
    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (primes[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                primes[i] = false;
        }
    }
    return primes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<bool> primes = Seive(n);
    for (int i = 0; i <= n; i++)
        if (primes[i])
            cout << i << " ";
    // Print Primes Upto N
    return 0;
}