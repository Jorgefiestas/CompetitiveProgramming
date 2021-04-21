#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, m, k, c[N];
bool a[N], b[N];
vector<int> group[4];

void readLike(bool arr[]) {
	int sz, x;
	cin >> sz;
	for (int i = 0; i < sz; i++) {
		cin >> x;
		arr[x - 1] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	readLike(a);
	readLike(b);

	for (int i = 0; i < n; i++) {
		if (a[i] && b[i]) {
			group[3].emplace_back(c[i]);
		}
		else if (a[i]) {
			group[1].emplace_back(c[i]);
		}
		else if (b[i]) {
			group[2].emplace_back(c[i]);
		}
		else {
			group[0].emplace_back(c[i]);
		}
	}

	int no = group[0].size();
	int oa = group[1].size();
	int ob = group[2].size();
	int ab = group[3].size();

	for (int i = 0; i < 4; i++) {
		sort(group[i].begin(), group[i].end());
	}

	if (k > m || 2 * k - ab > m || ab + min(oa, ob) < k) {
		cout << -1 << '\n';
		return 0;
	}

	priority_queue<int, vector<int>, greater<int>> free;
	for (int x : group[0]) {
		free.push(x);
	}

	int sx = max({0, k - oa, k - ob});
	int obg = k - sx;
	int fre = m - 2 * k + sx;

	long long can = 0;

	for (int i = 0; i < sx; i++) {
		can += group[3][i];
	}
	for (int i = k; i < ab; i++) {
		free.push(group[3][i]);
	}
	for (int i = 0; i < max(oa, ob); i++) {
		if (i < obg) {
			can += group[1][i];
			can += group[2][i];
		}
		else {
			if (i < oa) {
				free.push(group[1][i]);
			}
			if (i < ob) {
				free.push(group[2][i]);
			}
		}
	}

	for (int i = 0; i < fre; i++) {
		can += free.top();
		free.pop();
	}

	long long ans = can;
	for (int x = sx; x < min(ab, k); x++) {
		obg -= 1;
		can -= group[1][obg];
		can -= group[2][obg];

		free.push(group[1][obg]);
		free.push(group[2][obg]);

		can += group[3][x];
		can += free.top();
		free.pop();

		ans = min(ans, can);
	}

	cout << ans << '\n';

	return 0;
}
