#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 15;
const int mod = 1e9 + 7;
int cnt[N];

int add(int x, int y) { 
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

void calc() {
	vector<int> dcnt(10, 0);
	dcnt[0] = 1;
	cnt[0] = 1;

	for (int i = 1; i < N; i++) {
		int c9 = dcnt[9];
		for (int d = 9; d > 0; d--) {
			dcnt[d] = dcnt[d - 1];
		}
		dcnt[0] = c9;
		dcnt[1] = add(dcnt[1], c9);
		cnt[i] = add(cnt[i - 1], c9);
	}
}

int solve() {
	int n, m;
	cin >> n >> m;

	int ans = 0;
	while (n) {
		ans = add(ans, cnt[n % 10 + m]);
		n /= 10;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	calc();

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
