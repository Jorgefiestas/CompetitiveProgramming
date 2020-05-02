#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, b[N];
long long a[N], ft[N];
bool occ[N];

long long query(int idx) {
	long long sum = 0;
	while (idx > 0) {
		sum += ft[idx];
		idx -= idx & -idx;
	}
	return sum;
}

void update(int idx, long long val) {
	while (idx < N) {
		ft[idx] += val;
		idx += idx & -idx;
	}
}

long long add(long long m) {
	return m * (m + 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = n; i > 0; i--) {
		int l = 1; 
		int r = n;
		int m;

		while (l <= r) {
			m = (l + r) / 2;
			
			long long sum = add(m - 1) - query(m - 1);
			if (!occ[m] && sum == a[i]) {
				b[i] = m;
				occ[m] = true;
				update(m, m);
				break;
			}

			if (sum <= a[i]) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << b[i] << ' ';
	}
	cout << endl;

	return 0;
}
