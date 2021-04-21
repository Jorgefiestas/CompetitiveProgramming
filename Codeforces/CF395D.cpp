#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int A = 1e6 + 10;
int n, a[N], lft[N], rgt[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	stack<int> back;
	for (int i = 1; i <= n; i++) {
		while (!back.empty() && a[back.top()] % a[i] == 0) {
			back.pop();
		}
		lft[i] = i - (back.empty() ? 0 : back.top()) - 1;
		back.push(i);
	}

	stack<int> front;
	for (int i = n; i > 0; i--) {
		while (!front.empty() && a[front.top()] % a[i] == 0) {
			front.pop();
		}
		rgt[i] = (front.empty() ? n + 1 : front.top()) - i - 1;
		front.push(i);
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, lft[i] + rgt[i]);
	}

	set<int> res;
	for (int i = 1; i <= n; i++) {
		if (lft[i] + rgt[i] == mx) {
			res.insert(i - lft[i]);
		}
	}

	cout << res.size() << ' ' << mx << '\n';
	for (int x : res) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
