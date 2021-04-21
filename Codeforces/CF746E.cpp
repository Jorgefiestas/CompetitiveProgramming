#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, m, a[N];
map<int, int> ncnt;

void impossible() {
	cout << -1 << '\n';
	exit(0);
}

int get_unused(int & x) {
	while (ncnt.count(x)) {
		x += 2;
	}
	ncnt[x] += 1;

	if (x > m) {
		impossible();
	}

	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int pcnt[2] = {0, 0};

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ncnt[a[i]] += 1;
		pcnt[a[i] & 1] += 1;
	}

	if (n & 1) {
		impossible();
	}

	int freeOdd = 1;
	int freeEven = 2;
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (ncnt[a[i]] == 1) continue;

		ncnt[a[i]] -= 1;
		pcnt[a[i] & 1] -= 1;
		ans += 1;

		if (pcnt[0] < pcnt[1]) {
			a[i] = get_unused(freeEven);
			pcnt[0] += 1;
		}
		else {
			a[i] = get_unused(freeOdd);
			pcnt[1] += 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (pcnt[a[i] & 1] <= pcnt[!(a[i] & 1)]) continue;

		ans += 1;
		if (a[i] & 1) {
			a[i] = get_unused(freeEven);
			pcnt[1] -= 1;
			pcnt[0] += 1;
		}
		else {
			a[i] = get_unused(freeOdd);
			pcnt[0] -= 1;
			pcnt[1] += 1;
		}
	}

	cout << ans << '\n';

	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
