#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int K = 10;
const int mod = 1e9 + 7;
int n, m, k;
int chash, myHashed[K][K];
vector<int> deg[N];
vector<int> adjList[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

struct Hash {
	int a[N];

	Hash() {
		random_device rd;
		mt19937 gen(rd());

		uniform_int_distribution<> ud(1, mod - 1);

		for (int i = 0; i < N; i++) {
			a[i] = ud(gen);
		}
	}

	int operator()(const vector<int> &v) {
		int myHash = 0;
		for (int x : v) {
			myHash = ::add(myHash, a[x]);
		}
		return myHash;
	}
};
Hash myHash;

struct edg {
	int a, b, w;

	bool operator< (const edg &e) const {
		return w < e.w;
	}
};
edg edges[N];

int bt(int deg, int h) {
	if (deg == k + 1) {
		return (h == chash);
	}
	int ans = 0;
	for (int i = 0; i < deg; i++) {
		ans += bt(deg + 1, add(h, myHashed[deg][i]));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	}

	sort(edges, edges + n);

	for (int i = 0; i < m; i++) {
		int a = edges[i].a;
		int b = edges[i].b;
		adjList[a].emplace_back(b);
	}

	for (int i = 1; i <= n; i++) {
		deg[adjList[i].size()].emplace_back(i);
	}

	vector<int> cvec;
	for (int i = 1; i <= n; i++) {
		cvec.emplace_back(i);
	}
	chash = myHash(cvec);

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < i; j++) {
			vector<int> st;
			for (int v : deg[i]) {
				st.emplace_back(adjList[v][j]);
			}
			int hs = myHash(st);
			myHashed[i][j] = hs;
		}
	}

	cout << bt(1, 0) << '\n';

	return 0;
}
