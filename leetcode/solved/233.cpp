#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string s;
    int f[12][2][12];
    bool vs[12][2][12];

    int dfs(int pos, bool tight, int cnt1) {
        // pos: current digit index
        // tight: are we still bounded by n
        // cnt1: number of digit 1's so far
        if (pos == s.size()) { return cnt1; }

        if (vs[pos][tight][cnt1]) { return f[pos][tight][cnt1]; }

        vs[pos][tight][cnt1] = true;
        int &res = f[pos][tight][cnt1];
        res = 0;

        int limit = tight ? s[pos] - '0' : 9;
        for (int d = 0; d <= limit; d++) {
            res += dfs(pos + 1, tight && d == limit, cnt1 + (d == 1));
        }
        return res;
    }

    int countDigitOne(int n) {
        s = to_string(n);
        memset(vs, false, sizeof(vs));
        return dfs(0, true, 0);
    }
};

int main() {
    Solution s;
    cout << s.countDigitOne(13) << endl;
    return 0;
}
