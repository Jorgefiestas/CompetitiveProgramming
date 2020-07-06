#include <bits/stdc++.h>
using namespace std;
const int N = 800;
const int M = 2e5 + 10;
int n, m, a[N];
long long least[N];

int solve(long long b) {
	priority_queue<int> pq;

	int ans = 0;
	long long sum = b;
	for (int i = 0; i < n; i++) {
		sum += (long long) a[i];
		pq.push(-a[i]);

		if (sum < 0) {
			sum += (long long) pq.top();
			pq.pop();
			ans += 1;
		}
	}

	return ans;
}

long long bs(int x) {
	long long l = 0;
	long long r = 1e15 + 10;

	long long ans = -1;
	while (l <= r) {
		long long m = (l + r) / 2;
		int cnt = solve(m);

		if (cnt <= x) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i <= n; i++) {
		least[i] = bs(i);
	}

	long long b;
	for (int i = 0; i < m; i++) {
		cin >> b;
		int ans = lower_bound(least, least + n + 1, b, greater<long long>()) - least;
		cout << ans << '\n';
	}

	return 0;
}
