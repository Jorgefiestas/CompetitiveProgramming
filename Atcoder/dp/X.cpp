#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n;
long long dp[100005];

struct Block {
	int w = 0;
	int s = 0;
	long long v = 0;
	
	void read() {
		cin >> w >> s >> v;
	}

	bool operator <(const Block &b) const {
		return w + s < b.w + b.s;
	}
};

Block blocks[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		blocks[i].read();
	}

	sort(blocks, blocks + n);

	for (int i = 0; i < n; i++) {
		Block b = blocks[i];
		for (int w = b.s; w >= 0; w--) {
			dp[w + b.w] = max(dp[w + b.w], dp[w] + b.v);
		}
	}

	cout << *max_element(dp, dp + 100000) << '\n';

	return 0;
}
