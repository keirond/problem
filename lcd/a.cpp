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

    Point operator+(const Point &v) const { return {x + v.x, y + v.y}; }
    Point operator-(const Point &v) const { return {x - v.x, y - v.y}; }
    Point operator*(double k) const { return {x * k, y * k}; }
    Point operator/(double k) const { return {x / k, y / k}; }
    Point perp() const { return {-y, x}; }
    double dot(const Point &v) const { return x * v.x + y * v.y; }
};

using P = Point;

class Solution {
  public:
    int count(vector<vector<int>> &darts, const P &c, double r) {
        int ans = 0;
        for (auto &d : darts) {
            P u(d[0], d[1]);
            double dist2 = (u - c).dot(u - c);
            if (dist2 < r * r + 1e-9) { ans++; }
        }
        return ans;
    }

    int numPoints(vector<vector<int>> &darts, int r) {
        int n = darts.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            P u(darts[i][0], darts[i][1]);
            for (int j = i + 1; j < n; j++) {
                P v(darts[j][0], darts[j][1]);

                P m = (u + v) / 2;

                P uv = v - u;
                double dist2 = uv.dot(uv);
                if (dist2 < 1e-9) { continue; }
                double h2 = (double)r * r - dist2 / 4;
                if (h2 < -1e-9) { continue; }
                if (h2 < 1e-9) {
                    int t = count(darts, m, r);
                    ans = max(ans, t);
                } else {
                    P puv = uv.perp();
                    double h = sqrt(max(0.0, h2));
                    double dist = sqrt(max(0.0, dist2));
                    int t;
                    t = count(darts, m + puv * h / dist, r);
                    ans = max(ans, t);
                    t = count(darts, m - puv * h / dist, r);
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
    perform(Solution(), &Solution::numPoints, grid, v);
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
