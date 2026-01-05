#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;
    int countPartitions(vector<int> &nums, int k) {
        int n = nums.size();

        vector<long long> f(n + 1), p(n + 2);
        p[n + 1] = 0;
        f[n] = 1;
        p[n] = 1;

        deque<pair<int, int>> mndq, mxdq;
        int r = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (!mxdq.empty() && nums[i] > mxdq.back().first) {
                mxdq.pop_back();
            }
            mxdq.push_back({nums[i], i});
            while (!mndq.empty() && nums[i] < mndq.back().first) {
                mndq.pop_back();
            }
            mndq.push_back({nums[i], i});
            while (r >= i) {
                if (!mxdq.empty() && r < mxdq.front().second) {
                    mxdq.pop_front();
                }
                if (!mndq.empty() && r < mndq.front().second) {
                    mndq.pop_front();
                }
                if (mxdq.front().first - mndq.front().first > k) {
                    r--;
                } else {
                    break;
                }
            }

            f[i] = (p[i + 1] - p[r + 2]) % mod;
            f[i] = (f[i] + mod) % mod;
            p[i] = (p[i + 1] + f[i]) % mod;
        }
        return f[0];
    }
};
