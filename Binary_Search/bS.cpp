#include <bits/stdc++.h>

using namespace std;
#define ll long long

int isPresent(int x, vector<int> &a)
{
    int l = 0, h = a.size() - 1, mid;
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (a[mid] == x)
            return mid;
        else if (x > a[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a = {1,
                         3,
                         4,
                         6,
                         8,
                         9,
                         11,
                         14,
                         16};
        int bs = isPresent(n, a);
        if (bs == -1)
            cout << "Not Present\n";
        else
            cout << "Present at " << bs + 1 << "th Index\n";
    }
    return 0;
}