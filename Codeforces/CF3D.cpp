#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;
const int N = 5e4 + 10;
int n;
long long ans, change[N];
string str;

void invert(int idx) {
	str[idx] = (str[idx] == '(') ? ')' : '(';
	ans += change[idx];
	change[idx] = -change[idx];
}

void balance(int s, int e, int d, char p) {
	set<pii> left, right;
	for (int i = 0; i < n; i++) {
		if (str[i] == p) {
			right.insert({change[i], i});
		}
	}

	int score = 0;
	for (int i = s; i != e; i += d) {
		right.erase({change[i], i});
		if (str[i] != p) {
			left.insert({change[i], i});
		}

		score += (str[i] == p) ? 1 : -1;

		if (score < 0) {
			auto lft = left.begin();
			auto rgt = right.begin();
			invert(lft->second);
			invert(rgt->second);
			left.erase(lft);
			right.erase(rgt);
			score += 2;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	n = str.size();

	set<pii> open, close;

	int a, b;
	int op = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] != '?') {
			change[i] = 1e12;
			op += (str[i] == '(') ? 1 : -1;
		}
		else {
			cin >> a >> b;
			str[i] = (a < b) ? '(' : ')';
			ans += (long long) min(a, b);
			change[i] = abs(a - b);
			op += (a < b) ? 1 : -1;
		}

		if (str[i] == '(') {
			open.insert({change[i], i});
		}
		else {
			close.insert({change[i], i});
		}
	}

	if (n % 2) {
		cout << -1 << '\n';
		return 0;
	}

	while (op > 0) {
		auto it = open.begin();
		invert(it->second);
		open.erase(it);
		op -= 2;
	}
	while (op < 0) {
		auto it = close.begin();
		invert(it->second);
		close.erase(it);
		op += 2;
	}

	balance(0, n, 1, '(');
	balance(n - 1, -1, -1, ')');

	if (ans >= 1e12) {
		cout << -1 << '\n';
	}
	else { 
		cout << ans << '\n';
		cout << str << '\n';
	}

	return 0;
}
