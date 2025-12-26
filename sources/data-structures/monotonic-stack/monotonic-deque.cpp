#include <bits/stdc++.h>
using namespace std;

void maxValuesOfSubarraysSizeK(vector<int> &nums, int k) {
    int n = nums.size();
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && nums[i] > dq.back().second) { dq.pop_back(); }
        while (!dq.empty() && i - k >= dq.front().first) { dq.pop_front(); }
        dq.push_back({i, nums[i]});
        cout << dq.front().second << ' ';
    }
    cout << endl;
}

void minValuesOfSubarraysSizeK(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && nums[i] < dq.back().second) { dq.pop_back(); }
        while (!dq.empty() && i - k >= dq.front().first) { dq.pop_front(); }
        dq.push_back({i, nums[i]});
        cout << dq.front().second << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 4, 5, 6, 2, 1};
    maxValuesOfSubarraysSizeK(nums, 2);
    minValuesOfSubarraysSizeK(nums, 2);
    return 0;
}
