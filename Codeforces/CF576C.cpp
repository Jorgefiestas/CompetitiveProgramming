#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e3 + 1;
int n;
vector<pii> rect[N];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int xi, yi;
	for (int i = 1; i <= n; i++) {
		cin >> xi >> yi;
		rect[xi / N].emplace_back(yi, i);
	}

	vector<int> ans;

	for (int i = 0; i < N; i++) {
		if (i % 2) {
			sort(rect[i].begin(), rect[i].end());
		}
		else {
			sort(rect[i].begin(), rect[i].end(), greater<pii>());
		}

		for (auto [y, idx] : rect[i]) {
			ans.emplace_back(idx);
		}
	}

	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
