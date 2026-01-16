#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

vector<int> color;
vector<int> stk;
vector<int> pos;

bool dfs(int u) {
    color[u] = 1;
    pos[u] = stk.size();
    for (auto [v, i] : adj[u]) {
        stk.push_back(i);
        if (color[v] == 0) {
            if (dfs(v)) { return true; }
        } else if (color[v] == 1) {
            stk.erase(begin(stk), begin(stk) + pos[v]);
            return true;
        }
        stk.pop_back();
    }
    color[u] = 2;
    pos[u] = 0;
    return false;
}

int main() {
    cin >> n >> m;
    adj.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
    }

    pos.assign(n, 0);
    color.assign(n, 0);
    for (int u = 0; u < n; u++) {
        if (color[u] == 0) {
            if (dfs(u)) { break; }
        }
    }

    if (stk.empty()) {
        cout << -1 << endl;
        return 0;
    }
    cout << stk.size() << '\n';
    for (int i : stk) { cout << i << '\n'; }
    cout << flush;
    return 0;
}
