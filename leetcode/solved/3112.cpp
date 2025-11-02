#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> minimumTime(int n, vector<vector<int>> &edges,
                            vector<int> &disappear) {

        vector<unordered_map<int, int>> adj(n);
        for (auto &d : edges) {
            if (!adj[d[0]].contains(d[1])) {
                adj[d[0]][d[1]] = d[2];
            } else {
                adj[d[0]][d[1]] = min(adj[d[0]][d[1]], d[2]);
            }
            if (!adj[d[1]].contains(d[0])) {
                adj[d[1]][d[0]] = d[2];
            } else {
                adj[d[1]][d[0]] = min(adj[d[1]][d[0]], d[2]);
            }
        }

        vector<long long> f(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
                pq;
        f[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d >= disappear[u] || d > f[u]) { continue; }
            for (auto [v, vw] : adj[u]) {
                int w = d + vw;
                if (w < disappear[v] && w < f[v]) {
                    f[v] = w;
                    pq.emplace(w, v);
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (f[i] == LLONG_MAX || f[i] >= disappear[i]) {
                ans[i] = -1;
            } else {
                ans[i] = f[i];
            }
        }
        return ans;
    }
};

