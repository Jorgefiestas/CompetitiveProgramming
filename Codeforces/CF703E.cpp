#include <bits/stdc++.h>
using namespace std;
using pil = pair<int, long long>;
const int N = 1005;
const int M = 7000;
int n, m, tran[N][M];
long long a[N], b[N], k;
vector<long long> divisors;
map<long long, int> to_idx;
pil dp[N][M];

void find_divisors() {
	long long i;
	for (i = 1; i * i < k; i++) {
		if (k % i) continue;
		divisors.push_back(i);
		to_idx[i] = m++;
		divisors.push_back(k / i);
		to_idx[k / i] = m++;
	}
	if (i * i ==  k) {
		divisors.push_back(i);
		to_idx[i] = m++;
	}
}

int main() {
	scanf("%d %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
		b[i] = __gcd(a[i], k);
	}

	if (k == 1) {
		printf("1\n");
		printf("%ld\n", distance(a, min_element(a, a + n)) + 1);
		return 0;
	}

	find_divisors();

	dp[0][0] = {0, 0};
	for (int di = 1; di < m; di++) {
		long long d = divisors[di];
		tran[0][di] = di;
		if (a[0] % d) {
			dp[0][di].first = 3000;
		}
		else {
			dp[0][di].first = 1;
			dp[0][di].second = a[0];
			tran[0][di] = -1;
		}
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = {0, 0};
		for (long long di = 1; di < m; di++) {
			dp[i][di] = dp[i - 1][di];
			tran[i][di] = di;

			long long d = divisors[di];
			int g = __gcd(d, b[i]);
			if (g == 1) {
				continue;
			}

			int dj = to_idx[d / g];

			pil op = dp[i - 1][dj];
			op.first++;
			op.second += a[i];

			if (op < dp[i][di])  {
				dp[i][di] = op;
				tran[i][di] = dj;
			}
		}
	}

	if (dp[n - 1][1].first > n) {
		cout << -1 << '\n';
		return 0;
	}

	cout << dp[n - 1][1].first << '\n';

	int di = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (di != tran[i][di]) {
			printf("%d ", i + 1);
		}
		di = tran[i][di];
	}
	printf("\n");
	
	return 0;
}
