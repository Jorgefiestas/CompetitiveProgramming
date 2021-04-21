#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 16) + 10;
int t, dist[N];
bool vis[N];
vector<int> adjList[17];

bool check(int bm) {
	if (!bm) return true;
	int msb = __builtin_ctz(bm);
	return msb > 7;
}

int swap_bit(int bm, int i, int j) {
	int bi = !!(bm &(1 << i));
	int bj = !!(bm &(1 << j));

	int x = bi ^ bj;
	x = (x << i) | (x << j);
	return bm ^ x;
}

void bfs() {
	queue<int> q;

	for (int i = 0; i < (1 << 16); i++) {
		if (!check(i)) continue;
		vis[i] = true;
		dist[i] = 0;
		q.push(i);
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (dist[v] > 3) break;

		for (int i = 1; i <= 15; i++) {
			for (int j : adjList[i]) {
				int nbm = swap_bit(v, i - 1, j - 1);
				if (!vis[nbm]) {
					vis[nbm] = true;
					dist[nbm] = dist[v] + 1;
					q.push(nbm);
				}
			}
		}
	}
}

void solve() {
	int bm = 0;

	int b;
	for (int i = 0; i < 16; i++) {
		cin >> b;
		bm |= (b << i);
	}

	if (dist[bm] <= 3) {
		cout << dist[bm] << '\n';
	}
	else {
		cout << "more\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	adjList[1] = {2, 3, 5, 9};
	adjList[2] = {4, 6, 10};
	adjList[3] = {4, 7, 11};
	adjList[4] = {8, 12};
	adjList[5] = {6, 7, 13};
	adjList[6] = {8, 14};
	adjList[7] = {8, 15};
	adjList[8] = {16};
	adjList[9] = {10, 11, 13};
	adjList[10] = {12, 14};
	adjList[11] = {12, 15};
	adjList[12] = {16};
	adjList[13] = {14, 15};
	adjList[14] = {16};
	adjList[15] = {16};

	memset(dist, 1, sizeof dist);
	bfs();

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return  0;
}
