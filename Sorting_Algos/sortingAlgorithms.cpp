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
int n;

using namespace std;
// In Place Sorting Algo
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
    }
}
// Not a stable soritng algo
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minInd = 0, prevMin = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < prevMin)
            {
                prevMin = arr[j];
                minInd = j;
            }
        }
        swap(arr[i], arr[minInd]);
    }
}
// stable Sort algorith
void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//
void merge(vector<int> &arr, int l, int mid, int r)
{
    int n = mid - l + 1;
    int m = r - mid;
    vector<int> lArr(n), rArr(m);
    for (int i = 0; i < n; i++)
        lArr[i] = arr[l + i];

    for (int i = 0; i < m; i++)
        rArr[i] = arr[mid + 1 + i];
    int i = 0, j = 0;
    int k = l;
    while (i < n && j < m)
    {
        if (lArr[i] <= rArr[j])
        {
            arr[k] = lArr[i];
            i++;
        }
        else
        {
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        arr[k] = lArr[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr[k] = rArr[j];
        j++;
        k++;
    }
}
//Merge Sort Func
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
signed main()
{
    // Coder --> binary_Rahul
    // College --> NIT Raipur
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // For T number of test cases.
    int n;
    n = 5;
    vector<int> arr = {5, 3, 6, 2, 1};
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    mergeSort(arr, 0, n - 1);
    out(arr);
    return 0;
}