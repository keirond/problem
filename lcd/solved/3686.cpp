#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countStableSubsequences(vector<int> &nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<long long> f{0, 0, 1, 0, 0}, nf;
        for (int i = 0; i < n; i++) {
            nf = f;
            if (nums[i] % 2) {
                nf[0] = (f[1] + nf[0]) % mod;
                nf[1] = ((f[2] + f[3]) % mod + (f[4] + nf[1]) % mod) % mod;
            } else {
                nf[3] = ((f[0] + f[1]) % mod + (f[2] + nf[3]) % mod) % mod;
                nf[4] = (f[3] + nf[4]) % mod;
            }
            f = nf;
        }
        long long ans = 0;
        for (int i = 0; i < 5; i++) {
            if (i != 2) { ans = (ans + f[i]) % mod; }
        }
        return ans;
    }
};

