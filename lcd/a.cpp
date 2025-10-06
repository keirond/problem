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

int v [[maybe_unused]];
long long l [[maybe_unused]];
double d [[maybe_unused]];
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

// * START ******************************************************************

class Solution {
public:

    // n%2 == 0 => up -> up, down -> down
    // n%2 == 1 => up -> down, down -> up
    // f[0][up][i]
    // f[0][down][i]
    // f[1][up] = f[0][up][i][t] + f[0][down][t][j]
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9 + 7;
        int K = 31;
        int m = r - l + 1;
        vector<vector<vector<vector<int>>>> f(
                K, vector<vector<vector<int>>>(
                           2, vector<vector<int>>(m, vector<int>(m))));
        // f[k][i][up] is zzArray size 2^k up / down from i
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) { f[0][0][i][j] = 1; }
            for (int j = i + 1; j < m; j++) { f[0][1][i][j] = 1; }
        }

        for (int i = 0; i < m; i++) {
            for (int t = 0; t < i; t++) {
                for (int j = t + 1; j < m; j++) {
                    f[1][0][i][j] =
                            (f[1][0][i][j] +
                             1LL * f[0][0][i][t] * f[0][1][t][j] % mod) %
                            mod;
                }
            }
            for (int t = i + 1; t < m; t++) {
                for (int j = 0; j < t; j++) {
                    f[1][1][i][j] =
                            (f[1][1][i][j] +
                             1LL * f[0][1][i][t] * f[0][0][t][j] % mod) %
                            mod;
                }
            }
        }

        for (int k = 2; k < K; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    for (int t = 0; t < m; t++) {
                        f[k][0][i][j] = (f[k][0][i][j] +
                                         1LL * f[k - 1][0][i][t] *
                                                 f[k - 1][0][t][j] % mod) %
                                        mod;
                        f[k][1][i][j] = (f[k][1][i][j] +
                                         1LL * f[k - 1][1][i][t] *
                                                 f[k - 1][1][t][j] % mod) %
                                        mod;
                    }
                }
            }
        }

        vector<long long> g1(m, 1), g2(m, 1);
        for (int k = 0; k < K; k++) {
            if (n & (1 << k)) {
                vector<long long> ng1(m), ng2(m);
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        ng1[i] = (ng1[i] + 1LL * f[k][0][i][j] * g1[j] % mod) %
                                 mod;
                        ng2[i] = (ng2[i] + 1LL * f[k][1][i][j] * g2[j] % mod) %
                                 mod;
                    }
                }
                g1 = ng1, g2 = ng2;
            }
        }

        return (g1.back() + g2.front()) % mod;
    }
};

// * END ********************************************************************

void solve(int test_case [[maybe_unused]]) {
    int n, l, r;
    perform(Solution(), &Solution::zigZagArrays, n, l, r);
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
