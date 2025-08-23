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

void __info(int x) {
	if (x == INT_MIN)
		cerr << "-I";
	else if (x == INT_MAX)
		cerr << "I";
	else
		cerr << x;
}
void __info(long x) { cerr << x; }
void __info(long long x) {
	if (x == INT_MIN || x == LLONG_MIN)
		cerr << "-I";
	else if (x == INT_MAX || x == LLONG_MAX)
		cerr << "I";
	else
		cerr << x;
}
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

// --------------------------------------------------------------------------
// Runner (only Leetcode)

vector<int> arr [[maybe_unused]], nums [[maybe_unused]];
vector<string> strs [[maybe_unused]];
vector<vector<int>> grid [[maybe_unused]];
vector<vector<string>> strss [[maybe_unused]];

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

class Solution {
  public:
	int minimumVisitedCells(vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();

		vector<vector<int>> f(n, vector<int>(m, -1));
		f[0][0] = 1;

		vector<int> furRow(n, -1), furCol(m, -1);
		deque<pair<int, int>> dq;
		dq.push_back({0, 0});

		while (!dq.empty()) {
			auto [x, y] = dq.front();
			dq.pop_front();

			if (grid[x][y] == 0) continue;

			int l, r;

			// Jump down in column y
			l = max(furCol[y], x + 1);
			r = min(n - 1, x + grid[x][y]);
			for (int i = l; i <= r; i++) {
				if (f[i][y] == -1) {
					f[i][y] = f[x][y] + 1;
					dq.push_back({i, y});
				}
			}
			furCol[y] = max(furCol[y], r + 1);

			// Jump right in row x
			l = max(furRow[x], y + 1);
			r = min(m - 1, y + grid[x][y]);
			for (int i = l; i <= r; i++) {
				if (f[x][i] == -1) {
					f[x][i] = f[x][y] + 1;
					dq.push_back({x, i});
				}
			}
			furRow[x] = max(furRow[x], r + 1);

			if (f[n - 1][m - 1] != -1) return f[n - 1][m - 1];
		}

		return -1;
	}
};

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	perform(Solution(), &Solution::minimumVisitedCells, grid);
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