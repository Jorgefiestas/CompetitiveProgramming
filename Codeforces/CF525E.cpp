#include <bits/stdc++.h>
using namespace std;
const int F = 19;
const int N = 13;
int n, n1, n2, k;
long long s, a[N], b[N], fact[F];
map<long long, int> cnt[N + 1];

void bt1(int idx, int used, long long sum) {
	if (sum > s) {
		return;
	}
	if (idx == n1) {
		cnt[used][sum] += 1;
		return;
	}

	long long ans = 0;

	bt1(idx + 1, used, sum);
	bt1(idx + 1, used, sum + a[idx]);

	if (a[idx] < F && used < k) {
		bt1(idx + 1, used + 1, sum + fact[a[idx]]);
	}
}

long long bt2(int idx, int rem, long long sum) {
	if (sum > s) {
		return 0;
	}
	if (idx == n2) {
		rem = min(rem, n1);
		return cnt[rem][s - sum];
	}

	long long ans = 0;

	ans += bt2(idx + 1, rem, sum);
	ans += bt2(idx + 1, rem, sum + b[idx]);

	if (b[idx] < F && rem > 0) {
		ans += bt2(idx + 1, rem - 1, sum + fact[b[idx]]);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < F; i++) {
		fact[i] = fact[i - 1] * i;
	}

	cin >> n >> k >> s;

	n1 = n / 2;
	n2 = n - n / 2;

	for (int i = 0; i < n / 2 ; i++) {
		cin >> a[i];
	}
	for (int i = n / 2; i < n; i++) {
		cin >> b[i - n / 2];
	}

	bt1(0, 0, 0);

	for (int i = 0; i <= n1; i++) {
		for (auto [s, c] : cnt[i]) {
			cnt[i + 1][s] += c;
		}
	}

	cout << bt2(0, k, 0) << '\n';

	return 0;
}
