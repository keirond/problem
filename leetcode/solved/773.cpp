#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int slidingPuzzle(vector<vector<int>> &board) {
        int k = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) { k = k * 10 + board[i][j]; }
        }
        int s = 123450;

        int ans = 0;
        deque<int> dq, ndq;
        vector<int> vt(543211);
        dq.push_back(k);
        vt[k] = 1;

        auto convert = [&](vector<int> &t, int i, int j) {
            swap(t[i], t[j]);
            int ans = 0;
            for (int i = 0; i < 6; i++) { ans = ans * 10 + t[i]; }
            swap(t[i], t[j]);
            if (!vt[ans]) {
                vt[ans] = 1;
                ndq.push_back(ans);
            }
        };

        vector<vector<int>> mp{{1, 3}, {0, 2, 4}, {1, 5},
                               {0, 4}, {1, 3, 5}, {2, 4}};

        while (!dq.empty()) {
            ndq.clear();
            for (int d : dq) {
                if (d == s) { return ans; }
                vector<int> temp(6);
                int j = 0;
                for (int i = 5; i >= 0; i--) {
                    temp[i] = d % 10;
                    if (!temp[i]) { j = i; }
                    d /= 10;
                }
                for (int t : mp[j]) { convert(temp, j, t); }
            }
            dq = ndq;
            ans++;
        }
        return -1;
    }
};

