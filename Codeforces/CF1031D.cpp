#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2005;
int n, k, dp[N][N];
char a[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
		a[i][0] = '~';
		a[i][n + 1] = '~';
	}

	for (int i = 0; i <= n + 1; i++) {
		a[n + 1][i] = '~';
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i][j] == 'a') {
				dp[i][j] += 1;
			}
		}
	}

	int na = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i + j - 1 > dp[i][j] + k) continue;
			na = max(dp[i][j] + k, na);
		}
	}
	na = min(na, 2 * n - 1);

	set<pii> candidates;

	if (na == 0) {
		candidates.insert({1, 0});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i + j - 1 == na && dp[i][j] + k == na) {
				candidates.insert({i, j});
			}
		}
	}

	string post;
	while (post.size() + na < 2 * n - 1) {
		set<pii> ncandidates;
		char best = '~';
		for (pii p : candidates) {
			int i = p.first;
			int j = p.second;

			if (a[i + 1][j] < best) {
				ncandidates.clear();
				best = a[i + 1][j];
			}
			if (a[i + 1][j] == best) {
				ncandidates.insert({i + 1, j});
			}

			if (a[i][j + 1] < best) {
				ncandidates.clear();
				best = a[i][j + 1];
			}
			if (a[i][j + 1] == best) {
				ncandidates.insert({i, j + 1});
			}
		}
		
		post += best;
		candidates = ncandidates;
	}

	for (int i = 0; i < na; i++) {
		cout << 'a';
	}
	cout << post << '\n';

	return 0;
}
