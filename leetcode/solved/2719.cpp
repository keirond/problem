#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;
    bool vs[23][2][401];
    int f[23][2][401];

    int dfs(string &s, int mxSm, int pos, bool tight, int sm) {
        if (sm > mxSm) { return 0; }
        if (pos == s.size()) { return 1; }

        if (vs[pos][tight][sm]) { return f[pos][tight][sm]; }

        vs[pos][tight][sm] = true;
        int &ans = f[pos][tight][sm];
        ans = 0;

        int limit = tight ? s[pos] - '0' : 9;
        for (int i = 0; i <= limit; i++) {
            ans += dfs(s, mxSm, pos + 1, tight && i == limit, sm + i);
        }
        return ans;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        string t = num1;
        int i = t.size() - 1;
        for (i = t.size() - 1; i >= 0 && t[i] == '0'; i--) {}
        t[i] = t[i] - 1;
        for (i++; i < t.size(); i++) { t[i] = '9'; }
        memset(vs, false, sizeof(vs));
        memset(f, 0, sizeof(f));
        int t1 = dfs(t, min_sum - 1, 0, true, 0);

        memset(vs, false, sizeof(vs));
        memset(f, 0, sizeof(f));
        int t2 = dfs(t, max_sum, 0, true, 0);

        memset(vs, false, sizeof(vs));
        memset(f, 0, sizeof(f));
        int t3 = dfs(num2, min_sum - 1, 0, true, 0);

        memset(vs, false, sizeof(vs));
        memset(f, 0, sizeof(f));
        int t4 = dfs(num2, max_sum, 0, true, 0);

        return (t4 - t3 - (t2 - t1)) % mod;
    }
};

int main() {
    Solution s;
    cout << s.count("4179205230", "7748704426", 8, 46) << endl;
    return 0;
}
