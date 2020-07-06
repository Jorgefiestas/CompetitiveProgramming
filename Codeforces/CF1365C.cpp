#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, a[N], b;
int idx[N], cnt[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		idx[a[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> b;
		int shift = (n + (idx[b] - i) % n) % n;
		cnt[shift]++;
	}

	cout << *max_element(cnt, cnt + n) << '\n';

	return 0;
}
