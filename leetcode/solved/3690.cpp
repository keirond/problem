#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minSplitMerge(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();

        int k = 0;
        unordered_map<int, int> mp;
        for (int d : nums2) {
            if (!mp.contains(d)) { mp[d] = (int)mp.size(); }
            k = k * 10 + mp[d];
        }

        int s = 0;
        for (int d : nums1) { s = s * 10 + mp[d]; }

        int ans = 0;
        vector<bool> vt(1e7);
        deque<int> dq, ndq;
        dq.push_back(s);
        vt[s] = 1;

        while (!dq.empty()) {
            ndq.clear();
            for (int d : dq) {
                if (d == k) { return ans; }
                vector<int> temp(n);
                for (int i = n - 1; i >= 0; i--) {
                    temp[i] = d % 10;
                    d /= 10;
                }

                for (int l = 0; l < n; l++) {
                    for (int r = l + 1; r <= n; r++) {
                        vector<int> left;
                        for (int i = 0; i < l; i++) { left.push_back(temp[i]); }
                        for (int i = r; i < n; i++) { left.push_back(temp[i]); }
                        for (int i = 0; i <= left.size(); i++) {
                            int nxt = 0;
                            for (int j = 0; j < i; j++) {
                                nxt = nxt * 10 + left[j];
                            }
                            for (int j = l; j < r; j++) {
                                nxt = nxt * 10 + temp[j];
                            }
                            for (int j = i; j < left.size(); j++) {
                                nxt = nxt * 10 + left[j];
                            }
                            if (!vt[nxt]) {
                                vt[nxt] = 1;
                                ndq.push_back(nxt);
                            }
                        }
                    }
                }
            }
            ans++;
            dq = ndq;
        }
        return -1;
    }
};

