#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 100;
int n, a[N], front[N], back[N], ans[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	stack<pii> last;

	last.push({0, 0});
	for (int i = 1; i <= n; i++) {
		while (a[i] <= last.top().first) {
			last.pop();
		}

		back[i] = i - last.top().second - 1;
		last.push({a[i], i});
	}

	while (!last.empty()) {
		last.pop();
	}

	last.push({0, n + 1});
	for (int i = n; i > 0; i--) {
		while (a[i] <= last.top().first) {
			last.pop();
		}

		front[i] = last.top().second - i - 1;
		last.push({a[i], i});
	}

	for (int i = 1; i <= n; i++) {
		int sz = back[i] + front[i] + 1;
		ans[sz] = max(ans[sz], a[i]);
	}

	for (int i = n; i > 0; i--) {
		ans[i] = max(ans[i], ans[i + 1]);
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}
