#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ins insert
#define mp make_pair
#define mtp make_tuple
#define lb lower_bound
#define ub upper_bound

#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define par(v, n) v.begin(), v.begin() + n

#define loop(i, s, e, j) \
	for (auto i = (s); ((j) > 0) ? (i <= (e)) : (i >= (e)); i += (j))
#define iter(i, n) range(i, 0, n - 1, 1)
#define each(i, arr) for (auto &i : (arr))

constexpr double EPS [[maybe_unused]] = 1e-9;
constexpr double PI [[maybe_unused]] = 3.14159265358979323846;
constexpr char nl [[maybe_unused]] = '\n';

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
		if (c == ']') break;
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
	for (auto i : x) cerr << (f++ ? ", " : ""), __info(i);
	cerr << "}";
}

template <typename T> void __info(const T &x) {
	int f = 0;
	cerr << '{';
	for (auto &i : x) cerr << (f++ ? ", " : ""), __info(i);
	cerr << "}";
}

template <typename T, typename V> void __info(const pair<T, V> &x) {
	cerr << '{', __info(x.first), cerr << ", ", __info(x.second), cerr << '}';
}

template <typename T, typename V, typename K>
void __info(const tuple<T, K, V> &x) {
	cerr << '{', __info(get<0>(x)), cerr << ", ", __info(get<1>(x)),
		cerr << ", ", __info(get<2>(x)), cerr << '}';
}

void __print() { cerr << ']' << nl; }

template <typename T, typename... V> void __print(T t, V... v) {
	__info(t);
	if (sizeof...(v)) cerr << ", ";
	__print(v...);
}

#ifdef INFO
#define enable_info() cerr << "Enabling debug logging..." << nl;
#define info(x...)                                                            \
	cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
	__print(x);                                                               \
	cerr << "\e[39m";
#else
#define enable_info()
#define info(x...)
#endif

// **************************************************************************

class Solution {
  public:
	using ll = long long;
	vector<int> maximumWeight(vector<vector<int>> &intervals) {
		int n = intervals.size();
		for (int i = 0; i < n; i++) intervals[i].push_back(i);
		sort(begin(intervals), end(intervals));
		auto get = [&](int r) {
			return upper_bound(begin(intervals), end(intervals),
							   vector<int>({r, INT_MAX, INT_MAX, INT_MAX})) -
				   begin(intervals);
		};
		auto comp = [&](vector<int> &x, vector<int> &y) {
			int n = x.size(), m = y.size();
			int t = min(n, m);
			for (int i = 0; i < t; i++) {
				if (intervals[x[i]][3] < intervals[y[i]][3]) return true;
			}
			return false;
		};

		vector<vector<pair<ll, vector<int>>>> dp(
			4, vector<pair<ll, vector<int>>>(n + 1));

		dp[0][n] = {INT_MIN, {}};
		for (int i = n - 1; i >= 0; i--) {
			dp[0][i] = {intervals[i][2], {i}};
			if (dp[0][i + 1].first > dp[0][i].first ||
				dp[0][i + 1].first == dp[0][i].first &&
					intervals[dp[0][i + 1].second[0]][3] < intervals[i][3])
				dp[0][i] = dp[0][i + 1];
		}

		for (int k = 1; k < 4; k++) {
			dp[k][n] = {INT_MIN, {}};

			for (int i = n - 1; i >= 0; i--) {
				int r = intervals[i][1];
				int w = intervals[i][2];

				dp[k][i] = {w, {i}};
				if (dp[k][i + 1].first > dp[k][i].first)
					dp[k][i] = dp[k][i + 1];

				int t = get(r);
				auto &t1 = dp[k][i], &t2 = dp[k - 1][t];
				if (t2.first + w >= t1.first) {
					vector<int> temp = {i};
					temp.insert(end(temp), begin(t2.second), end(t2.second));
					sort(begin(temp), end(temp), [&](int x, int y) {
						return intervals[x][3] < intervals[y][3];
					});
					if (t2.first + w > t1.first ||
						t2.first + w == t1.first && comp(temp, t1.second)) {
						t1.first = dp[k - 1][t].first + w;
						t1.second = temp;
					}
				}
			}
		}

		vector<pair<ll, vector<int>>> ans(4);
		for (int k = 0; k < 4; k++) {
			vector<int> temp;
			transform(begin(dp[k][0].second), end(dp[k][0].second),
					  back_inserter(temp),
					  [&](int x) { return intervals[x][3]; });
			sort(begin(temp), end(temp));
			ans[k] = {dp[k][0].first, temp};
		}
		sort(begin(ans), end(ans), [](auto &a, auto &b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first > b.first;
		});

		// info(intervals);
		// info(dp[0]);
		// info(dp[1]);
		// info(dp[2]);
		// info(dp[3]);
		// info(ans);
		return ans[0].second;
	}
};

void solve(int test_case [[maybe_unused]]) {
	vector<vector<int>> grid [[maybe_unused]];
	vector<int> arr [[maybe_unused]];
	vector<string> strs [[maybe_unused]];

	int v [[maybe_unused]];
	long long l [[maybe_unused]];
	double d [[maybe_unused]];
	char c [[maybe_unused]];
	string s, s1 [[maybe_unused]];

	Solution sol [[maybe_unused]];

	__read(grid);
	auto result = sol.maximumWeight(grid);
	info(result);
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