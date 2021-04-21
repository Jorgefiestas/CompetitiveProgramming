#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int A = 2e6 + 100;
using pii = pair<int, int>;
int n, a[N], cnt[N];
bool prime[A];

void sieve() {
	for (int i = 2; i < A; i++) {
		prime[i] = true;
	}

	for (int i = 2; i * i < A; i++) {
		if (!prime[i]) continue;
		for (int j  = i * i; j < A; j += i) {
			prime[j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	multiset<pii, greater<pii>> score;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || prime[a[i] + a[j]]) continue;
			cnt[i] += 1;
		}
		score.insert({cnt[i], a[i]});
	}

	while ((*score.begin()).first) {
		int x = (*score.begin()).second;
		score.erase(score.begin());

		vector<pii> toDel;
		vector<pii> toAdd;
		for (pii p : score) {
			int y = p.second;
			if (!prime[x + y]) {
				toDel.push_back(p);
				toAdd.push_back({p.first - 1, p.second});
			}
		}

		for (pii p : toDel) {
			score.erase(score.find(p));
		}
		for (pii p : toAdd) {
			score.insert(p);
		}
	}

	cout << score.size() << '\n';
	for (pii p : score) {
		cout << p.second << ' ';
	}
	cout << '\n';

	return 0;
}
