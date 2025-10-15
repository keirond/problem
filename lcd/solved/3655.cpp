#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int pown(int a, int n, int m) {
        int ans = 1;
        while (n) {
            if (n & 1) { ans = 1LL * ans * a % m; }
            a = 1LL * a * a % m;
            n >>= 1;
        }
        return ans;
    }

    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        int m = sqrt(n);
        int mod = 1e9 + 7;
        vector<vector<int>> f(m + 1, vector<int>(n, 1));
        for (auto &d : queries) {
            int l = d[0], r = d[1], k = d[2], v = d[3];
            if (k <= m) {
                f[k][l] = 1LL * f[k][l] * v % mod;
                int rr = r - (r - l) % k + k;
                if (rr < n) {
                    f[k][rr] = 1LL * f[k][rr] * pown(v, mod - 2, mod) % mod;
                }
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1LL * nums[i] * v % mod;
                }
            }
        }
        for (int k = 1; k <= m; k++) {
            for (int i = 0; i < n; i++) {
                if (i >= k) { f[k][i] = 1LL * f[k][i] * f[k][i - k] % mod; }
                nums[i] = 1LL * nums[i] * f[k][i] % mod;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) { ans ^= nums[i]; }
        return ans;
    }
};

