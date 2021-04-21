#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m;
set<int> vis;
set<int> trees;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	queue<pii> q;

	int xi;
	for (int i = 0; i < n; i++) {
		cin >> xi;
		q.push({xi, 0});
		vis.insert(xi);
	}

	long long d = 0;
	int cnt = 0;
	while (cnt < m) {
		int v = q.front().first;
		int dt = q.front().second;
		q.pop();

		if (dt > 0) {
			d += (long long) dt;
			cnt += 1;
			trees.insert(v);
		}

		if (!vis.count(v - 1)) {
			vis.insert(v - 1);
			q.push({v - 1, dt + 1});
		}
		if (!vis.count(v + 1)) {
			vis.insert(v + 1);
			q.push({v + 1, dt + 1});
		}
	}

	cout << d << '\n';
	for (int t : trees) {
		cout << t << ' ';
	}
	cout << '\n';
	
	return 0;
}
