#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int N = 1e6 + 1;
    vector<int> spf;
    void init() {
        spf.resize(N);
        iota(begin(spf), end(spf), 0);
        for (int i = 2; i < N; i++) {
            if (spf[i] == i) {
                for (long long j = 1LL * i * i; j < N; j += i) {
                    if (spf[j] == j) { spf[j] = i; }
                }
            }
        }
    }
    int findValidSplit(vector<int> &nums) {
        init();

        unordered_map<int, int> mp;
        for (int d : nums) {
            while (d != 1) {
                mp[spf[d]]++;
                d /= spf[d];
            }
        }

        int n = nums.size();
        unordered_map<int, int> temp;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            int d = nums[i];
            while (d != 1) {
                if (temp.contains(spf[d])) {
                    temp[spf[d]]--;
                    mp[spf[d]]--;
                    if (!temp[spf[d]]) { cnt--; }
                } else if (mp[spf[d]]) {
                    temp[spf[d]] = mp[spf[d]] - 1;
                    cnt++;
                    if (!temp[spf[d]]) { cnt--; }
                }
                d /= spf[d];
            }
            if (cnt == 0) { return i; }
        }
        return -1;
    }
};

