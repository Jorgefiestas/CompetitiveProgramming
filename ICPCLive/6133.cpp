#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 1e6 + 10;
int n, trie[N][26], child[N];
bool term[N];
string s[N];

int nodecnt;
void add(string &str) {
	int node = 0;
	for (char c : str) {
		int i = c - 'a';
		if (!trie[node][i]) {
			trie[node][i] = ++nodecnt;
			child[node]++;
		}
		node = trie[node][i];
	}
	term[node]  = true;
}

int query(const string &str) {
	int cnt = 0;
	int node = 0;
	for (char c : str) {
		int i = c - 'a';
		if (child[node] > 1 || term[node] || !node) {
			cnt++;
		}
		node = trie[node][i];
	}
	return cnt;
}

ld solve() {
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		add(s[i]);
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		num += query(s[i]);
	}

	return (ld) num / n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << fixed << setprecision(2);
	while (cin >> n) {
		memset(trie, 0, sizeof trie);
		memset(term, 0, sizeof term);
		memset(child, 0, sizeof child);
		nodecnt = 0;

		cout << solve() << '\n';
	}

	return 0;
}
