#include <bits/stdc++.h>
using namespace std;
const int N = 23;
int n, a[N], ans[N];
map<int, int> idx;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		idx[a[i]] = i;
	}

	sort(a, a + n);

	for (int i = 0; i < n - 1; i++) {
		ans[idx[a[i]]] = a[i + 1];
	}
	ans[idx[a[n - 1]]] = a[0];

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}
