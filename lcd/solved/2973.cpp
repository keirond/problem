#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    vector<vector<int>> adj;
    vector<bool> vt;

    vector<long long> ans;

    long long calc(vector<int> &nums) {
        int m = nums.size();
        long long ans = LLONG_MIN;
        ans = max(ans, 1LL * nums[0] * nums[1] * nums[2]);
        ans = max(ans, 1LL * nums[0] * nums[m - 1] * nums[m - 2]);
        return max(ans, 0LL);
    }

    vector<int> dfs(int u, vector<int> &cost) {
        vt[u] = 1;
        vector<int> temp{cost[u]};
        for (int v : adj[u]) {
            if (!vt[v]) {
                vector<int> cur = dfs(v, cost);
                for (int d : cur) { temp.push_back(d); }
            }
        }
        int m = temp.size();
        sort(begin(temp), end(temp), greater<>());
        vector<int> next;
        for (int i = 0; i < m; i++) {
            if (i == 0 || i == 1 || i == 2 || i == m - 2 || i == m - 1) {
                next.push_back(temp[i]);
            }
        }
        if (next.size() < 3) {
            ans[u] = 1;
        } else {
            ans[u] = calc(next);
        }
        return next;
    }

    vector<long long> placedCoins(vector<vector<int>> &edges,
                                  vector<int> &cost) {
        n = cost.size();
        adj.resize(n);
        vt.resize(n);
        for (auto &d : edges) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        ans.resize(n);
        dfs(0, cost);
        return ans;
    }
};

