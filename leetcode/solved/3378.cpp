#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<int, int> par;

    int parent(int u) {
        if (!par.contains(u) || par[u] == u) { return par[u] = u; }
        return par[u] = parent(par[u]);
    }

    void unite(int u, int v) {
        int x = parent(u), y = parent(v);
        if (x == y) { return; }
        if (x > y) { swap(x, y); }
        par[y] = x;
    }

    int countComponents(vector<int> &nums, int threshold) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = nums[i] * 2; j <= threshold; j += nums[i]) {
                unite(j, nums[i]);
            }
        }
        unordered_set<int> st;
        for (int d : nums) { st.insert(parent(d)); }
        return (int)st.size();
    }
};

