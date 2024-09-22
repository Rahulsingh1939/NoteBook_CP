#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> segTree;
void build_Segment(vector<int> &arr, int start, int end, int index)
{
    // If at Leaf Node
    if (start == end)
    {
        segTree[index] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    int left = 2 * index, right = 2 * index + 1;
    build_Segment(arr, start, mid, left);
    build_Segment(arr, mid + 1, end, right);
    segTree[index] = segTree[left] + segTree[right];
}

void update_Segment(vector<int> &arr, int start, int end, int index, int pos, int val)
{
    if (start == end)
    {
        arr[pos] = val;
        segTree[index] = arr[pos];
        return;
    }
    int mid = start + (end - start) / 2;
    if (pos <= mid)
        update_Segment(arr, start, mid, 2 * index, pos, val);
    else
        update_Segment(arr, mid + 1, end, 2 * index + 1, pos, val);

    // Update the current node after updating the child
    segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
}

int query(int start, int end, int index, int l, int r)
{
    // No overlap
    if (r < start || l > end)
        return 0;

    // Complete overlap
    if (start >= l && end <= r)
        return segTree[index];

    // Partial overlap
    int mid = start + (end - start) / 2;
    int left_ans = query(start, mid, 2 * index, l, r);
    int right_ans = query(mid + 1, end, 2 * index + 1, l, r);
    return left_ans + right_ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    segTree.resize(2 * n + 1);
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    int index = 1;
    build_Segment(arr, 0, n - 1, index);
    int q;
    cin >> q;
    int flag, l, r, pos, val;
    while (q--)
    {
        cin >> flag;
        // flag = 1 for Querying
        // flag = 2 for Updating the Segment Tree
        if (flag == 1)
        {
            cin >> l >> r;
            // l and r are 0 based
            cout << query(0, n - 1, index, l, r) << endl;
        }
        else
        {
            cin >> pos >> val;
            // pos is O based
            update_Segment(arr, 0, n - 1, index, pos, val);
        }
    }
    return 0;
}