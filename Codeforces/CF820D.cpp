#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, p[N], pivot[N];
int near, far;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		int ch = p[i] - i;
		ans += (long long) abs(ch);

		if (ch < 0) {
			ch = n + ch;
			far += 1;
		}
		else {
			near += 1;
		}
		
		pivot[ch] += 1;
	}

	long long score = ans;
	int shift = 0;
	for (int i = 0; i < n - 1; i++) {
		near -= pivot[i];
		far += pivot[i];

		far -= 1;
		score -= abs(n - p[n - i]);
		score -= near;
		score += far;
		score += abs(1 - p[n - i]);
		near += 1;

		if (score < ans) { 
			ans = score;
			shift = i + 1;
		}
	}

	cout << ans << ' ' << shift << '\n';

	return 0;
}
