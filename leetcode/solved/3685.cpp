#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    using ll = long long;
    vector<bool> subsequenceSumAfterCapping(vector<int> &nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<vector<bool>> f(k + 1, vector<bool>(n + 1));
        for (int i = 0; i <= n; i++) { f[0][i] = 1; }

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j + 1] = f[i][j];
                if (i >= nums[j]) {
                    f[i][j + 1] = f[i][j + 1] || f[i - nums[j]][j];
                }
            }
        }

        vector<bool> ans(n);
        for (int x = 0; x < n; x++) {
            for (int j = 0; 1LL * j * (x + 1) <= k; j++) {
                int t = upper_bound(begin(nums), end(nums), x + 1) -
                        begin(nums);
                if (j + t > n) { break; }
                if (f[k - 1LL * j * (x + 1)][t]) {
                    ans[x] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};

