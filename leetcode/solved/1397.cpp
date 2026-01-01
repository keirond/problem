#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;
    string sE;
    bool vs[501][2][51];
    int f[501][2][51];
    vector<int> lsp;

    int dfs(string &s, int pos, bool tight, int trackE) {
        if (trackE == sE.size()) { return 0; }
        if (pos == s.size()) { return 1; }
        if (vs[pos][tight][trackE]) { return f[pos][tight][trackE]; }

        vs[pos][tight][trackE] = true;
        int &ans = f[pos][tight][trackE];
        ans = 0;

        int limit = tight ? s[pos] - 'a' : 25;
        for (int i = 0; i <= limit; i++) {
            int j = trackE;
            while (j > 0 && sE[j] - 'a' != i) { j = lsp[j - 1]; }
            if (sE[j] - 'a' == i) { j++; }
            ans = (ans + dfs(s, pos + 1, tight && i == limit, j)) % mod;
        }
        return ans;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        int m = evil.size();
        lsp.resize(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && evil[i] != evil[j]) { j = lsp[j - 1]; }
            if (evil[i] == evil[j]) { j++; }
            lsp[i] = j;
        }

        sE = evil;

        memset(vs, false, sizeof(vs));
        memset(f, 0, sizeof(f));
        int t1 = dfs(s1, 0, true, 0);

        memset(vs, false, sizeof(vs));
        memset(f, 0, sizeof(f));
        int t2 = dfs(s2, 0, true, 0);

        int ans = (t2 - t1 + mod) % mod;
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && s1[i] != evil[j]) { j = lsp[j - 1]; }
            if (s1[i] == evil[j]) { j++; }
            if (j == m) { return ans; }
        }
        return ans + 1;
    }
};

int main() {
    Solution s;
    cout << s.findGoodStrings(2, "aa", "da", "b") << endl;
    return 0;
}
