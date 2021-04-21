#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 3e5 + 10;
int n, ax, bx;
pii c[N];

vector<int> a, b;

void solve(int i) {
	int idx = -1;

	for (int j = 1; j <= n - i; j++) {
		int rb = (bx + j - 1) / j;
		if (c[n - i - j].first < rb)
			continue;
		idx = j;
		break;
	}

	if (idx == -1) 
		return;

	for (int j = n - i; j < n; j++) {
		a.emplace_back(c[j].second);
	}
	for (int j = n - i - idx; j < n - i; j++) {
		b.emplace_back(c[j].second);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> ax >> bx;

	for (int i = 0; i < n; i++) {
		cin >> c[i].first;
		c[i].second = i + 1;
	}
	sort(c, c + n);

	bool swp = false;
	for (int rep = 0; rep < 2; rep++) {
		for (int i = 1; i <= n; i++) {
			int ra = (ax + i - 1) / i;
			if (c[n - i].first < ra) 
				continue;

			solve(i);
			break;
		}

		if (!a.empty())
			break;

		swap(ax, bx);
		swp = true;
	}

	if (a.empty()) {
		cout << "No\n";
		return 0;
	}

	if (swp)
		swap(a, b);

	cout << "Yes\n";

	cout << a.size() << ' ' << b.size() << '\n';

	for (int x : a) {
		cout << x << ' ' ;
	}
	cout << '\n';

	for (int x : b) {
		cout << x << ' ' ;
	}
	cout << '\n';

	return 0;
}
