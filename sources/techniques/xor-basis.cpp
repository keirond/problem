#include <bits/stdc++.h>
using namespace std;

// int minimumXorSubset(vector<int> &compacted_basis) {
//      // transform basis into reduced row-echelon form
// }

int maximumXorSubset(vector<int> &nums) {
    vector<int> basis(31);
    for (int d : nums) {
        int cur = d;
        for (int i = 30; i >= 0; i--) {
            if (cur & (1 << i)) {
                if (!basis[i]) {
                    basis[i] = cur;
                    break;
                }
                cur ^= basis[i];
            }
        }
    }

    vector<int> compacted_basis;
    for (int i = 0; i < 31; i++) {
        if (basis[i]) { compacted_basis.push_back(basis[i]); }
    }

    int n = compacted_basis.size();
    sort(begin(compacted_basis), end(compacted_basis), greater<>());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((ans ^ compacted_basis[i]) > ans) { ans ^= compacted_basis[i]; }
    }
    return ans;
}

int kThSmallestXorSubset(vector<int> &nums, int k) {
    vector<int> basis(31);
    for (int d : nums) {
        int cur = d;
        for (int i = 30; i >= 0; i--) {
            if (cur & (1 << i)) {
                if (!basis[i]) {
                    basis[i] = cur;
                    break;
                }
                cur ^= basis[i];
            }
        }
    }

    vector<int> compacted_basis;
    for (int i = 0; i < 31; i++) {
        if (basis[i]) { compacted_basis.push_back(basis[i]); }
    }

    int n = compacted_basis.size();
    sort(begin(compacted_basis), end(compacted_basis));
    int ans = 0;
    k--;
    for (int i = 0; i < n; i++) {
        if (k & (1 << i)) { ans ^= compacted_basis[i]; }
    }
    return ans;
}

bool checkIfTargetIsASubsetXorValue(vector<int> &nums, int target) {
    vector<int> basis(31);
    for (int d : nums) {
        int cur = d;
        for (int i = 30; i >= 0; i--) {
            if (cur & (1 << i)) {
                if (!basis[i]) {
                    basis[i] = cur;
                    break;
                }
                cur ^= basis[i];
            }
        }
    }

    for (int i = 30; i >= 0; i--) {
        if (target & (1 << i)) { target ^= basis[i]; }
    }
    return !target;
}

long long countSubsetXorValues(vector<int> &nums) {
    vector<int> basis(31);
    for (int d : nums) {
        int cur = d;
        for (int i = 31; i >= 0; i--) {
            if (cur & (1 << i)) {
                if (!basis[i]) {
                    basis[i] = cur;
                    break;
                }
                cur ^= basis[i];
            }
        }
    }

    vector<int> compacted_basis;
    for (int i = 0; i < 31; i++) {
        if (basis[i]) { compacted_basis.push_back(basis[i]); }
    }

    int n = compacted_basis.size();
    return 1LL << n;
    // return (1LL << n) - 1; // for counting distinct values of non-empty
    // subset
}

void constructAllSubsetXorValuesInOrder(vector<int> &nums) {
    vector<int> basis(31);
    for (int d : nums) {
        int cur = d;
        for (int i = 31; i >= 0; i--) {
            if (cur & (1 << i)) {
                if (!basis[i]) {
                    basis[i] = cur;
                    break;
                }
                cur ^= basis[i];
            }
        }
    }

    vector<int> compacted_basis;
    for (int i = 0; i < 31; i++) {
        if (basis[i]) { compacted_basis.push_back(basis[i]); }
    }

    int n = compacted_basis.size();
    for (int i = 0; i < (1 << n); i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { temp ^= compacted_basis[j]; }
        }
        cout << temp << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // cout << maximumXorSubset(nums) << endl;
    // cout << kThSmallestXorSubset(nums, 2) << endl;
    // cout << checkIfTargetIsASubsetXorValue(nums, 10) << endl;
    // cout << countSubsetXorValues(nums) << endl;
    // constructAllSubsetXorValuesInOrder(nums);
}
