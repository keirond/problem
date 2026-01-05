#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> adj;
    vector<int> grp;

    vector<bool> vis;
    vector<long long> f;
    vector<unordered_map<int, pair<int, long long>>> g;

    void dfs(int u) {
        long long &ans = f[u];
        unordered_map<int, pair<int, long long>> &freq = g[u];

        freq[grp[u]].first++;
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dfs(v);
                ans += f[v];
                for (auto [k, v1] : g[v]) {
                    long long t = v1.second + v1.first;
                    ans += t * freq[k].first;
                    ans += 1LL * v1.first * freq[k].second;
                    freq[k].first += v1.first;
                    freq[k].second += t;
                }
            }
        }
    }

    long long interactionCosts(int n, const vector<vector<int>> &edges,
                               const vector<int> &group) {
        adj.resize(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        grp = group;
        vis.assign(n, false);
        f.resize(n);
        g.resize(n);
        vis[0] = true;
        dfs(0);
        return f[0];
    }
};

int main() {
    Solution s;
    cout << s.interactionCosts(3, {{0, 1}, {1, 2}}, {3, 2, 3}) << endl;
    return 0;
}
