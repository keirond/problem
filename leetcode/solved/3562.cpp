#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int budget;
    vector<int> future, present;
    vector<vector<int>> adj;
    bool vs[161][2];
    int f[161][2][161];

    int *dfs(int u, bool dc) {
        if (vs[u][dc]) { return f[u][dc]; }

        vs[u][dc] = true;
        int *ans = f[u][dc];

        for (int v : adj[u]) {
            for (int i = budget; i >= 0; i--) {
                int *child = dfs(v, 0);
                for (int j = 0; j <= i; j++) {
                    ans[i] = max(ans[i], ans[i - j] + child[j]);
                }
            }
        }

        int p = 0;
        int c = dc ? present[u] / 2 : present[u];
        int t = budget - c;
        if (t >= 0) {
            vector<int> h(t + 1, 0);
            p += future[u] - c;
            for (int v : adj[u]) {
                for (int i = t; i >= 0; i--) {
                    for (int j = 0; j <= i; j++) {
                        h[i] = max(h[i], h[i - j] + dfs(v, 1)[j]);
                    }
                }
            }
            for (int i = 0; i <= t; i++) {
                ans[i + c] = max(ans[i + c], p + h[i]);
            }
        }

        return ans;
    }

    int maxProfit(int n, vector<int> &present, vector<int> &future,
                  vector<vector<int>> &hierarchy, int budget) {
        this->budget = budget;
        this->present = present;
        this->future = future;
        adj.resize(n);
        for (auto &e : hierarchy) { adj[e[0] - 1].push_back(e[1] - 1); }
        return dfs(0, 0)[budget];
    }
};

int main() {
    Solution s;
    int n = 2;
    vector<int> pr{1, 2};
    vector<int> fu{4, 3};
    vector<vector<int>> hi{{1, 2}};
    int bu = 3;
    cout << s.maxProfit(n, pr, fu, hi, bu) << endl;
    return 0;
}
