#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string s;
    int d;

    bool vs[10][2][2];
    int f[10][2][2];

    int dfs(int pos, bool tight, bool leadingZero) {
        if (pos == s.size()) { return 1; }

        if (vs[pos][tight][leadingZero]) { return f[pos][tight][leadingZero]; }

        vs[pos][tight][leadingZero] = true;
        int &ans = f[pos][tight][leadingZero];
        ans = 0;

        int limit = tight ? s[pos] - '0' : 9;
        for (int i = 0; i <= limit; i++) {
            if (leadingZero && i == 0) {
                ans += dfs(pos + 1, tight && i == limit, true);
            } else if (d & (1 << i)) {
                ans += dfs(pos + 1, tight && i == limit, false);
            }
        }
        return ans;
    }

    int atMostNGivenDigitSet(const vector<string> &digits, int n) {
        s = to_string(n);
        for (string c : digits) { d |= 1 << (c[0] - '0'); }

        memset(vs, false, sizeof(vs));
        return dfs(0, true, true) - 1;
    }
};

int main() {
    Solution s;
    cout << s.atMostNGivenDigitSet({"1", "3", "5", "7"}, 100) << endl;
    return 0;
}
