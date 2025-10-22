#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minCost(int n, vector<vector<int>> &edges, int k) {
        sort(begin(edges), end(edges),
             [](auto &x, auto &y) { return x[2] < y[2]; });

        vector<int> par(n);
        iota(begin(par), end(par), 0);

        vector<int> temp(n);
        int m = edges.size();
        int cnt = n - k;
        for (int i = 0; i < m; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            if (cnt > 0 && unite(par, x, y)) {
                cnt--;
                temp[get_par(par, x)] = max(temp[get_par(par, x)], w);
            }
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[get_par(par, i)] = max(mp[get_par(par, i)], temp[i]);
        }
        int ans = 0;
        for (auto [_, v] : mp) { ans = max(ans, v); }
        return ans;
    }

    int get_par(vector<int> &par, int x) {
        if (par[x] == x) { return x; }
        return par[x] = get_par(par, par[x]);
    }

    bool unite(vector<int> &par, int x, int y) {
        int u = get_par(par, x);
        int v = get_par(par, y);
        if (u == v) { return false; }
        if (u > v) { swap(u, v); }
        par[v] = u;
        return true;
    }
};

