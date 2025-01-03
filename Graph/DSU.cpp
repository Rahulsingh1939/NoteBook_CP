#include <bits/stdc++.h>
using namespace std;

class DisJointSet
{
    vector<int> rank, parent;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    // Find Parent function with Path Compression
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int pU = findPar(u);
        int pV = findPar(v);
        if (pU == pV)
            return;
        if (rank[pU] < rank[pV])
            parent[pU] = pV;
        else if (rank[pV] < rank[pU])
            parent[pV] = pU;
        else
        {
            parent[pV] = pU;
            rank[pU]++;
        }
    }
};

