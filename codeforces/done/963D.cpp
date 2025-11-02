#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<int> ks(n);
    vector<string> strs(n);
    for (int i = 0; i < n; i++) { cin >> ks[i] >> strs[i]; }

    int nn = 0;
    vector<int> link, end_link;
    vector<vector<int>> next, end;

    auto add = [&]() {
        next.emplace_back(26);
        link.emplace_back();
        end.emplace_back();
        end_link.emplace_back();
        return nn++;
    };
    add();

    for (int i = 0; i < n; i++) {
        string &s = strs[i];
        int u = 0;
        for (char c : s) {
            int d = c - 'a';
            if (!next[u][d]) { next[u][d] = add(); }
            u = next[u][d];
        }
        end[u].push_back(i);
    }

    deque<int> dq;
    for (dq.push_back(0); !dq.empty();) {
        int u = dq.front();
        dq.pop_front();
        for (int d = 0; d < 26; d++) {
            int v = next[u][d];
            if (!v) {
                next[u][d] = next[link[u]][d];
            } else {
                link[v] = u ? next[link[u]][d] : 0;
                end_link[v] =
                  end[link[v]].empty() ? end_link[link[v]] : link[v];
                dq.push_back(v);
            }
        }
    }

    auto adv = [&](int u, char c) {
        int d = c - 'a';
        while (u && !next[u][d]) { u = link[u]; }
        return next[u][d];
    };

    vector<int> ans(n, INT_MAX);
    vector<deque<int>> dq_ans(n);

    int u = 0;
    int sn = str.size();
    for (int i = 0; i < sn; i++) {
        u = adv(u, str[i]);
        int v = u;
        while (v) {
            for (int x : end[v]) {
                dq_ans[x].push_back(i);
                if (dq_ans[x].size() > ks[x]) { dq_ans[x].pop_front(); }
                if (dq_ans[x].size() >= ks[x]) {
                    ans[x] = min(
                      ans[x], dq_ans[x].back() + 1 -
                                (dq_ans[x].front() - (int)strs[x].size() + 1));
                }
            }
            v = end_link[v];
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == INT_MAX) { ans[i] = -1; }
        cout << ans[i] << nl;
    }
}

// **************************************************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--) {
        solve(test_cases);
        cout << flush;
    }
    return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************
