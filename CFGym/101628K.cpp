#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q; 
string v[N];

int trie[10 * N][26], nodecnt;
int cnt[10 * N];
set<int> pos[10 * N];
set<int> term[10 * N];

bool in(const set<int> &s, int l, int r) {
	return s.lower_bound(l) != s.upper_bound(r);
}

void insert(const string &str, int idx) {
	int node = 0;
	for (char c : str) {
		int i = c - 'a';
		if (!trie[node][i]) {
			trie[node][i] = ++nodecnt;
		}
		node = trie[node][i];
		pos[node].insert(idx);
		cnt[node]++;
	}
	term[node].insert(idx);
}

void remove(const string &str, int idx) {
	int node = 0;
	for (char c : str) {
		int i = c - 'a';
		node = trie[node][i];
		pos[node].erase(idx);
		cnt[node]--;
	}
	term[node].erase(idx);
}

bool vprefix(int l, int r, const string &str) {
	int node = 0;
	for (char c : str) {
		int i = c - 'a';
		if (!trie[node][i] || !cnt[trie[node][i]]){
			break;
		}
		node = trie[node][i];

		if (!in(pos[node], l, r)) {
			break;
		}

		if (in(term[node], l, r)) {
			return true;
		}
	}
	return false;
}

bool sprefix(int l, int r, const string &str) {
	int node = 0;
	for (char c : str) {
		int i = c - 'a';
		if (!trie[node][i] || !cnt[trie[node][i]]) {
			return false;
		}
		node = trie[node][i];

		if (!in(pos[node], l, r)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		insert(v[i], i);
	}

	cin >> q;

	string str;
	int op, l, r;
	for (int i = 0; i < q; i++) {
		cin >> op;

		if (op == 1) {
			cin >> l >> str;
			remove(v[l], l);
			insert(str, l);
			v[l] = str;
			continue;
		}

		cin >> l >> r >> str;
		bool ans = (op == 2) ? vprefix(l, r, str) : sprefix(l, r, str);

		if (ans) {
			cout << "Y\n";
		}
		else {
			cout << "N\n";
		}
	}

	return 0;
}
