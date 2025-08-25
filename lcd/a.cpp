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
	int ti = 0, sccs = 0, re = 0;
	vector<vector<int>> adj;
	vector<int> disc, _link;
	vector<bool> vt;
	deque<int> stk;
	void call(int u) {
		disc[u] = _link[u] = ti++;
		stk.push_back(u);
		vt[u] = 1;

		for (int v : adj[u]) {
			if (disc[v] == -1) {
				call(v);
				_link[u] = min(_link[u], _link[v]);
			} else if (vt[u]) {
				_link[u] = min(_link[u], disc[v]);
			}
		}

		if (disc[u] == _link[u]) {
			int ce = 0, cv = 0;
			int v;
			do {
				v = stk.back();
				vt[v] = 0;
				cv++;
				ce += adj[v].size();
				stk.pop_back();
			} while (v != u);
			sccs++;
			ce /= 2;
			re += ce - (cv - 1);
		}
	}
	int makeConnected(int n, vector<vector<int>> &connections) {
		adj.resize(n);
		for (auto &d : connections) {
			int u = d[0], v = d[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		disc.assign(n, -1);
		_link.resize(n);
		vt.resize(n);
		for (int i = 0; i < n; i++) {
			if (disc[i] == -1) call(i);
		}

		if (sccs - 1 > re) return -1;
		return sccs - 1;
	}
};

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	perform(Solution(), &Solution::makeConnected, v, grid);
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