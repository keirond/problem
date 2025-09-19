#include <bits/stdc++.h>

using namespace std;

constexpr char nl = '\n';

// --------------------------------------------------------------------------
// Data structures (only Leetcode)

template <typename T> struct LinkedListNode;
template <typename T> struct BinaryTreeNode;

template <typename T> struct LinkedListNode {
    T val;
    LinkedListNode *next;

    LinkedListNode() : val(T()), next(nullptr) {}
    LinkedListNode(T x) : val(x), next(nullptr) {}
    LinkedListNode(T x, LinkedListNode *next) : val(x), next(next) {}
};

template <typename T> struct BinaryTreeNode {
    T val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode() : val(T()), left(nullptr), right(nullptr) {}
    BinaryTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(T x, BinaryTreeNode *left, BinaryTreeNode *right)
        : val(x), left(left), right(right) {}
};

#define ListNode LinkedListNode<int>
#define TreeNode BinaryTreeNode<int>

// --------------------------------------------------------------------------
// Read methods (only Leetcode)

template <typename T> void __cin(stringstream &ss, T &value) { ss >> value; }

void __cin(stringstream &ss, char &value) {
    char c;
    ss >> c >> value >> c;
}

void __cin(stringstream &ss, string &value) {
    char c;
    ss >> c, getline(ss, value, '"');
}

template <typename T, typename V>
void __cin(stringstream &ss, pair<T, V> &values) {
    char c;
    ss >> c;
    __cin(ss, values.first);
    ss >> c;
    __cin<V>(ss, values.second);
    ss >> c;
}

template <typename T> void __cin(stringstream &ss, vector<T> &values) {
    char c;
    ss >> c;

    while (ss.peek() != ']') {
        T value;
        __cin(ss, value);
        values.push_back(value);
        ss >> c;
        if (c == ']') { break; }
    }
}

void __read() {}

template <typename T, typename... V> void __read(T &t, V &...v) {
    string str;
    getline(cin, str);
    stringstream ss(str);
    __cin(ss, t);
    __read(v...);
}

// --------------------------------------------------------------------------

template <typename T> void __info(const T &x);
template <typename T, typename V> void __info(const pair<T, V> &x);
template <typename T, typename V, typename K>
void __info(const tuple<T, V, K> &x);

void __info(int x) { cerr << x; }
void __info(long x) { cerr << x; }
void __info(long long x) { cerr << x; }
void __info(unsigned x) { cerr << x; }
void __info(unsigned long x) { cerr << x; }
void __info(unsigned long long x) { cerr << x; }
void __info(float x) { cerr << x; }
void __info(double x) { cerr << x; }
void __info(long double x) { cerr << x; }
void __info(char x) { cerr << '\'' << x << '\''; }
void __info(const char *x) { cerr << '\"' << x << '\"'; }
void __info(const string &x) { cerr << '\"' << x << '\"'; }
void __info(bool x) { cerr << (x ? "true" : "false"); }

void __info(const vector<bool> &x) {
    int f = 0;
    cerr << '{';
    for (auto i : x) { cerr << (f++ ? ", " : ""), __info(i); }
    cerr << "}";
}

template <typename T> void __info(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) { cerr << (f++ ? ", " : ""), __info(i); }
    cerr << "}";
}

template <typename T, typename V> void __info(const pair<T, V> &x) {
    cerr << '{', __info(x.first), cerr << ", ", __info(x.second), cerr << '}';
}

template <typename T, typename K, typename V>
void __info(const tuple<T, K, V> &x) {
    cerr << '{', __info(get<0>(x)), cerr << ", ", __info(get<1>(x)),
            cerr << ", ", __info(get<2>(x)), cerr << '}';
}

void __print() { cerr << ']' << nl; }

template <typename T, typename... V> void __print(T t, V... v) {
    __info(t);
    if (sizeof...(v)) { cerr << ", "; }
    __print(v...);
}

#ifdef INFO
#define enable_info() cerr << "Enabling debug logging..." << nl;
#define info(x...)                                                             \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";  \
    __print(x);                                                                \
    cerr << "\e[39m";
#else
#define enable_info()
#define info(x...)
#endif

// --------------------------------------------------------------------------
// Runner (only Leetcode)

vector<int> arr [[maybe_unused]], nums [[maybe_unused]];
vector<string> strs [[maybe_unused]];
vector<vector<int>> grid [[maybe_unused]];
vector<vector<string>> str_grid [[maybe_unused]];

int v [[maybe_unused]], val [[maybe_unused]];
long long l [[maybe_unused]], lg [[maybe_unused]];
double d [[maybe_unused]], dd [[maybe_unused]];
char c [[maybe_unused]], ch [[maybe_unused]];
string s [[maybe_unused]], str [[maybe_unused]];

template <typename Obj, typename MemFn, typename... Args>
void perform(Obj &&obj, MemFn memfn, Args &&...args) {
    __read(args...);

    if constexpr (std::is_void_v<decltype(std::invoke(
                          memfn, std::forward<Obj>(obj),
                          std::forward<Args>(args)...))>) {
        std::invoke(memfn, std::forward<Obj>(obj), std::forward<Args>(args)...);
    } else {
        auto result = std::invoke(memfn, std::forward<Obj>(obj),
                                  std::forward<Args>(args)...);
        __info(result);
        cerr << nl;
    }
}

// **************************************************************************

class Solution {
public:

    int mod = 1e9 + 7;
    vector<vector<long long>> tr;

    vector<long long> merge(vector<long long> &l, vector<long long> &r) {
        vector<long long> temp(4);
        temp[0] = max(max(l[0] + r[2], l[1] + r[0]), l[1] + r[2]);
        temp[1] = max(max(l[0] + r[3], l[1] + r[1]), l[1] + r[3]);
        temp[2] = max(max(l[2] + r[2], l[3] + r[0]), l[3] + r[2]);
        temp[3] = max(max(l[2] + r[3], l[3] + r[1]), l[3] + r[3]);
        return temp;
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) {
            tr[node][0] = v;
            return;
        }
        int m = l + (r - l >> 1);
        if (i <= m) {
            update(node << 1, l, m, i, v);
        } else {
            update(node << 1 | 1, m + 1, r, i, v);
        }
        tr[node] = merge(tr[node << 1], tr[node << 1 | 1]);
    }

    vector<long long> query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) { return {}; }
        if (ql <= l && r <= qr) { return tr[node]; }
        int m = l + (r - l >> 1);
        auto left = query(node << 1, l, m, ql, qr);
        auto right = query(node << 1 | 1, m + 1, r, ql, qr);
        if (left.empty()) { return right; }
        if (right.empty()) { return left; }
        return merge(left, right);
    }

    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
        int mod = 1e9 + 7;
        int n = nums.size();
        tr.assign(n * 4, vector<long long>(4));
        for (int i = 0; i < n; i++) { update(1, 0, n - 1, i, nums[i]); }

        int m = queries.size();
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            update(1, 0, n - 1, queries[i][0], queries[i][1]);
            auto t = query(1, 0, n - 1, 0, n - 1);
            ans = (ans + *max_element(begin(t), end(t))) % mod;
            ans = (ans + mod) % mod;
        }
        return ans;
    }
};

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
    perform(Solution(), &Solution::maximumSumSubsequence, nums, grid);
}

// **************************************************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    enable_info();
    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--) {
        solve(test_cases);
        cout << flush;
    }
    return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************
