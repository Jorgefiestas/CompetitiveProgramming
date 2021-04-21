#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
using pii = pair<int, int>;
int n, m, k;
vector<pii> milk;
set<int> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	int fi;
	for (int i = 1; i <= n; i++) {
		cin >> fi;
		milk.push_back({fi + 1, -1});
	}

	int si;
	for (int i = 1; i <= m; i++) {
		cin >> si;
		milk.push_back({si + 1, i});
	}

	sort(milk.begin(), milk.end());

	int sum = 0;
	for (auto [d, idx] : milk) {
		if (sum == (long long) k * d) {
			if (idx != -1) continue;
			if (ans.empty()) {
				cout << -1 << '\n';
				return 0;
			}
			ans.erase(ans.begin());
			sum -= 1;
		}
		sum += 1;
		if (idx != -1) {
			ans.insert(idx);
		}
	}

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
