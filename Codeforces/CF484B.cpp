#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n;
int gst[N];

int query(int l, int r) {
	if (gst[r] >= l) {
		return gst[r];
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 

	set<int> values;

	int ai;
	for (int i = 1; i <= n; i++) {
		cin >> ai;
		gst[ai] = ai;
		values.insert(ai);
	}

	for (int i = 0; i < N; i++) {
		gst[i] = max(gst[i], gst[i - 1]);
	}

	int ans = 0;

	for (int x : values) {
		int can = -1;
		for (int y = x; y < 1e6; y += x) {
			int q = query(y, y + x - 1);
			can = max(can, q - y);
		}
		ans = max(ans, can);
	}

	cout << ans << '\n';

	return 0;
}
