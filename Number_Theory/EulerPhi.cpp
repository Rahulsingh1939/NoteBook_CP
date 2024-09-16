#include <bits/stdc++.h>

using namespace std;
#define ll long long
/*Euler's totient function, also known as phi-function  
$\phi (n)$ , counts the number of integers between 1 and  
n inclusive, which are coprime to b.
Two numbers are coprime if their greatest common divisor equals  
1 ( 1  is considered to be coprime to any number).*/

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

vector<int> phi_1_to_n(int n)
{
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << phi(n) << endl;
    vector<int> res = phi_1_to_n(n);
    for (auto &it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}