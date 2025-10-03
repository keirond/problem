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
                if (j == 0) {
                    convert(temp, 0, 1);
                    convert(temp, 0, 3);
                }
                if (j == 1) {
                    convert(temp, 1, 0);
                    convert(temp, 1, 2);
                    convert(temp, 1, 4);
                }
                if (j == 2) {
                    convert(temp, 2, 1);
                    convert(temp, 2, 5);
                }
                if (j == 3) {
                    convert(temp, 3, 0);
                    convert(temp, 3, 4);
                }
                if (j == 4) {
                    convert(temp, 4, 1);
                    convert(temp, 4, 3);
                    convert(temp, 4, 5);
                }
                if (j == 5) {
                    convert(temp, 5, 4);
                    convert(temp, 5, 2);
                }
            }
            dq = ndq;
            ans++;
        }
        return -1;
    }
};

