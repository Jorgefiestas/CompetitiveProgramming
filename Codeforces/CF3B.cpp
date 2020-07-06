#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 10;
int n, v, vol[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> v;

	vector<pii> boats[3];

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		boats[a].push_back({b, i + 1});
	}

	sort(boats[1].rbegin(), boats[1].rend());
	sort(boats[2].rbegin(), boats[2].rend());

	int n = boats[1].size();
	int m = boats[2].size();

	boats[1].push_back({0, 0});

	int ans = 0;
	vector<int> res;

	int i = 0;
	int j = 0;

	if (v & 1) {
		ans += boats[1][0].first;
		res.emplace_back(boats[1][0].second);
		i += 1;
		v -= 1;
	}

	while (v && (i < n || j < m)) {
		if (j >= m) {
			ans += boats[1][i].first;
			res.emplace_back(boats[1][i].second);
			i += 1;
			v -= 1;
			continue;
		}
		if (i >= n) {
			ans += boats[2][j].first;
			res.emplace_back(boats[2][j].second);
			j += 1;
			v -= 2;
			continue;
		}
		
		int c1 = boats[1][i].first + boats[1][i + 1].first;
		int c2 = boats[2][j].first;

		if (c1 > c2) {
			ans += c1;
			res.emplace_back(boats[1][i].second);

			if (boats[1][i + 1].second) {
				res.emplace_back(boats[1][i + 1].second);
			}
			else {
				v += 1;
			}

			i += 2;
		}
		else {
			ans += c2;
			res.emplace_back(boats[2][j].second);
			j += 1;
		}
		v -= 2;
	}

	cout << ans << '\n';
	for (int x : res) {
		if (!x) continue;
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
