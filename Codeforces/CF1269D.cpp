#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long cnt[2] = {0, 0};

	for (int i = 0; i < n; i++) {
		bool c = i & 1;
		cnt[c] += (long long) a[i] / 2;
		cnt[!c] += (long long) (a[i] + 1) / 2;
	}

	cout << min(cnt[0], cnt[1]) << '\n';

	return 0;
}
