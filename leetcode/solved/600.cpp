#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> bits;
    bool vs[30][2][2];
    int f[30][2][2];

    int dfs(int pos, bool tight, bool set) {
        if (pos == bits.size()) { return 1; }
        if (vs[pos][tight][set]) { return f[pos][tight][set]; }

        vs[pos][tight][set] = true;
        int &ans = f[pos][tight][set];
        ans = 0;

        int limit = tight ? bits[pos] : 1;
        for (int i = 0; i <= (set ? 0 : limit); i++) {
            ans += dfs(pos + 1, tight && i == limit, i == 1);
        }
        return ans;
    }

    int findIntegers(int n) {
        int t = n;
        while (t) {
            bits.push_back(t & 1);
            t >>= 1;
        }
        reverse(begin(bits), end(bits));
        memset(vs, false, sizeof(vs));
        return dfs(0, true, false);
    }
};

int main() {
    Solution s;
    cout << s.findIntegers(6) << endl;
    return 0;
}
