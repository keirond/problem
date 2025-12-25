#include <bits/stdc++.h>
using namespace std;

void twoPointers(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1; // init pointers
    while (l < r) {
        // .. do something
    }
}

void slidingWindow(vector<int> &nums) {
    int n = nums.size();
    for (int l = 0, r = 0; r < n; r++) {
        while (l <= r /* && !(stop condition) */) { l++; }
        // .. do something
    }
}

void slowFastPointer(vector<int> &nums) {
    int slow = 0, fast = 0;
    while (f(fast) && f(f(fast))) {
        slow = f(slow);
        fast = f(f(fast));
        if (slow == fast) {
            // handle result
            break;
        }
    }
}

int main() {}
