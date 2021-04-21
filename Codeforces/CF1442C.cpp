#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const int N = 2e5 + 10;
const int mod = 998244353;
int n, m;
vector<int> adjList[N][2];
bool vis[N][25];

struct Node {
	int v, k, d;

	bool operator<(const Node& u) const {
		if (k == u.k) {
			return d > u.d;
		}
		if (k > 20 || u.k > 20) {
			return k > u.k;
		}
		return ((1 << k) + d) > ((1 << u.k) + u.d);
	}
};

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int exp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a][0].emplace_back(b);
		adjList[b][1].emplace_back(a);
	}

	int ans;

	priority_queue<Node> pq;
	pq.push({1, 0, 0});

	while (!pq.empty()) {
		Node curr = pq.top();
		pq.pop();

		if (curr.v == n) {
			ans = sub(add(curr.d, exp(2, curr.k)), 1);
			break;
		}


		int par = curr.k % 2;
		int nk = curr.k;
		if (nk > 20) {
			nk = 20 + nk % 2;
		}

		if (vis[curr.v][nk]) continue;
		vis[curr.v][nk] = true;

		for (int u : adjList[curr.v][par]) {
			pq.push({u, curr.k, curr.d + 1});
		}
		pq.push({curr.v, curr.k + 1, curr.d});
	}

	cout << ans << '\n';

	return 0;
}
