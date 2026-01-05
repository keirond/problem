#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> adj;
    vector<bool> vis;

    long long dfs(int u) {
        for (int v : adj[u]) {
            if (!vis[v]) { dfs(v); }
        }
    }

    long long interactionCosts(int n, vector<vector<int>> &edges,
                               vector<int> &group) {
        adj.resize(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.resize(n);
    }
};
