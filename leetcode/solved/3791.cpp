#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool vs[16][2][9 * 15 + 1];
    long long f[16][2][9 * 15 + 1];

    // included 0000000000 (not a correct case)
    // but it still works because t2 - t1 removes it
    long long dfs(const string &s, int pos, bool tight, int sm) {
        if (pos == s.size()) { return sm == 72; }

        if (vs[pos][tight][sm]) { return f[pos][tight][sm]; }

        vs[pos][tight][sm] = true;
        long long &ans = f[pos][tight][sm];
        ans = 0;

        int limit = tight ? s[pos] - '0' : 9;
        for (int i = 0; i <= limit; i++) {
            int nsm = sm + ((pos % 2) ? i : -i);
            ans += dfs(s, pos + 1, tight && i == limit, nsm);
        }
        return ans;
    }

    long long countBalanced(long long low, long long high) {
        memset(vs, false, sizeof(vs));
        memset(f, 0, sizeof(f));
        long long t1 = dfs(to_string(low - 1), 0, true, 72);

        memset(vs, false, sizeof(vs));
        memset(f, 0, sizeof(f));
        long long t2 = dfs(to_string(high), 0, true, 72);

        return t2 - t1;
    }
};
