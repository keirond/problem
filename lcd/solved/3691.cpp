#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> min_tr, max_tr;
    vector<int> lg;

    long long maxTotalValue(vector<int> &nums, int k) {
        int n = nums.size();
        int K = __lg(n) + 1;

        min_tr.assign(K, vector<int>(n));
        max_tr.assign(K, vector<int>(n));
        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) { lg[i] = lg[i / 2] + 1; }
        for (int i = 0; i < n; i++) {
            min_tr[0][i] = nums[i];
            max_tr[0][i] = nums[i];
        }
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << (j - 1)) < n; i++) {
                min_tr[j][i] = min(min_tr[j - 1][i],
                                   min_tr[j - 1][i + (1 << (j - 1))]);
                max_tr[j][i] = max(max_tr[j - 1][i],
                                   max_tr[j - 1][i + (1 << (j - 1))]);
            }
        }

        priority_queue<pair<long long, pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({(long long)query_max(i, n - 1) - query_min(i, n - 1),
                     {i, n - 1}});
        }

        long long ans = 0;
        for (int j = 0; j < k; j++) {
            if (pq.empty()) { break; }
            auto &d = pq.top();
            ans += d.first;
            auto [l, r] = d.second;
            pq.pop();
            if (l >= r) { continue; }
            pq.push({(long long)query_max(l, r - 1) - query_min(l, r - 1),
                     {l, r - 1}});
        }
        return ans;
    }

    int query_min(int l, int r) {
        int i = lg[r - l + 1];
        return min(min_tr[i][l], min_tr[i][r - (1 << i) + 1]);
    }

    int query_max(int l, int r) {
        int i = lg[r - l + 1];
        return max(max_tr[i][l], max_tr[i][r - (1 << i) + 1]);
    }
};

