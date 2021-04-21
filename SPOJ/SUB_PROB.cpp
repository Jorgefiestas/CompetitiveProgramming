#include <bits/stdc++.h>
using namespace std;
int n;
string str;

struct SuffixAutomaton {
	struct state {
		int len, link;
		long long path;
		bool vis;
		map<char, int> next;
	};
	
	static const int MAX_N = 2e5 + 100;

	int last = -1;
	int sz = 1;
	state st[MAX_N];

	void build(const string &str) {
		for (int i = 0; i < sz; i++) {
			st[i].vis = 0;
			st[i].next.clear();
		}

		st[0].len = 0;
		st[0].link = -1;
		sz = 1;
		last = 0;

		for (char c : str) {
			sa_extend(c);
		}
	}

	void sa_extend(char c) {
		int cur = sz++;
		st[cur].len = st[last].len + 1;
		int p = last;
		while (p != -1 && !st[p].next.count(c)) {
			st[p].next[c] = cur;
			p = st[p].link;
		}
		if (p == -1) {
			st[cur].link = 0;
		} else {
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len) {
				st[cur].link = q;
			} else {
				int clone = sz++;
				st[clone].len = st[p].len + 1;
				st[clone].next = st[q].next;
				st[clone].link = st[q].link;
				while (p != -1 && st[p].next[c] == q) {
					st[p].next[c] = clone;
					p = st[p].link;
				}
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}

	bool find(const string &str) {
		int node = 0;
		for (char c : str) {
			if (!st[node].next.count(c)) {
				return false;
			}
			node = st[node].next[c];
		}
		return true;
	}

} sa;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	sa.build(str);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (sa.find(str)) {
			cout << "Y\n";
		}
		else {
			cout << "N\n";
		}
	}

	return 0;
}
