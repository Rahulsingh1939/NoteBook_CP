#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<long long> tree, lazy;
    int n;

    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void propagate(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val)
    {
        propagate(node, start, end);
        if (start > r || end < l)
            return;
        if (start >= l && end <= r)
        {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int node, int start, int end, int idx)
    {
        propagate(node, start, end);
        if (start == end)
            return tree[node];
        int mid = (start + end) / 2;
        if (idx <= mid)
            return query(2 * node, start, mid, idx);
        else
            return query(2 * node + 1, mid + 1, end, idx);
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int l, int r, int val)
    {
        updateRange(1, 0, n - 1, l, r, val);
    }

    long long get(int idx)
    {
        return query(1, 0, n - 1, idx);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(arr);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            st.update(l - 1, r - 1, val);
        }
        else if (type == 2)
        {
            int idx;
            cin >> idx;
            cout << st.get(idx - 1) << "\n";
        }
    }
    return 0;
}