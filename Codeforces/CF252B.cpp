#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N];

bool check() {
	bool asc = true;
	bool dsc = true;
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[i - 1]) {
			dsc = false;
		}
		if (a[i] > a[i - 1]) {
			asc = false;
		}
	}

	return !asc && !dsc;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	bool dif = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1 && a[i] != a[i - 1]) {
			dif =  true;
		}
	}

	if (n < 3 || !dif) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == a[i]) continue;
			swap(a[i], a[j]);
			if (check()) {
				cout << i << ' ' << j << '\n';
				return 0;
			}
			swap(a[i], a[j]);
		}
	}

	cout << -1 << '\n';
	return 0;
}
