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
void perform(Obj &&obj, MemFn &&memfn, Args &&...args) {
    __read(args...);
    if constexpr (std::is_void_v<decltype((std::forward<Obj>(obj).*memfn)(
                    std::forward<Args>(args)...))>) {
        (std::forward<Obj>(obj).*memfn)(std::forward<Args>(args)...);
    } else {
        auto result =
          (std::forward<Obj>(obj).*memfn)(std::forward<Args>(args)...);
        __info(result);
        cerr << nl;
    }
}

// **************************************************************************

struct Point {
    double x, y;

    Point perp() { return {-y, x}; }
    Point operator-(Point &v) { return {x - v.x, y - v.y}; }
};

class Solution {
  public:
    using ll = long long;

    vector<Point> circleCircleIntersection(Point &c1, double r1, Point &c2,
                                           double r2) {
        Point d = (c2 - c1).perp();

        
    }

    vector<pair<int, int>> intersect(vector<int> c1, vector<int> c2) {
        ll dist2 = 1LL * (c1[0] - c2[0]) * (c1[0] - c2[0]) +
                   1LL * (c1[1] - c2[1]) * (c1[1] - c2[1]);
        ll rr2 = ((ll)c1[2] + c2[2]) * ((ll)c1[2] + c2[2]);
        if (dist2 > rr2) { return {}; }
    }
    bool canReachCorner(ll xCorner, ll yCorner, vector<vector<int>> &circles) {
        int n = circles.size();
        vector<bool> vt(n);

        deque<vector<int>> dq;
        for (int i = 0; i < n; i++) {
            auto d = circles[i];
            d.push_back(i);
            if (abs(d[0]) <= d[2] && d[1] >= 0 && d[1] <= yCorner) {
                dq.push_back(d);
            } else if (abs(yCorner - d[1]) <= d[2] && d[0] >= 0 &&
                       d[0] <= xCorner) {
                dq.push_back(d);
            }
        }

        while (!dq.empty()) {
            auto cr = dq.back();
            dq.pop_back();
            if (vt[cr[3]]) { continue; }
            vt[cr[3]] = 1;

            if (abs(xCorner - cr[0]) <= cr[2] && cr[1] >= 0 &&
                cr[1] <= yCorner) {
                return false;
            } else if (abs(cr[1]) <= cr[2] && cr[0] >= 0 && cr[0] <= xCorner) {
                return false;
            }
            for (int i = 0; i < n; i++) {
                auto &t = circles[i];
                if (!vt[i] && 1LL * (t[0] - cr[0]) * (t[0] - cr[0]) +
                                  1LL * (t[1] - cr[1]) * (t[1] - cr[1]) <=
                                ((ll)t[2] + cr[2]) * ((ll)t[2] + cr[2])) {
                    auto d = t;
                    d.push_back(i);
                    dq.push_back(d);
                }
            }
        }
        return true;
    }
};

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
    int v1, v2, v3;
    perform(Solution(), &Solution::canReachCorner, v1, v2, grid);
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
