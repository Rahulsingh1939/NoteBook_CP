#include <bits/stdc++.h>

using namespace std;
#define ll long long

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b)
{
    return (a * (b / gcd(a, b)));
}

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << "GCD = " << gcd(a, b) << endl;
    cout << "LCM = " << lcm(a, b) << endl;
    // For the eqn of form Ax + by = C, We can use ExtendedEuclidean to Find the solutions.
    int x, y;
    cout << "GCD = " << gcdExtended(a, b, &x, &y) << endl;
    cout << "x = " << x << " y = " << y << endl;
    return 0;
}