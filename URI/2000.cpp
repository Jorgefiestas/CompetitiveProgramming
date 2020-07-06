#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
int t;
string s1, s2;

struct SuffixAutomaton {
	struct state {
		int len, link;
		long long path;
		bool vis;
		map<char, int> next;
	};

	int last = -1;
	int sz = 0;
	state st[MAX_N];

	void rebuild(const string &str) {
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

	long long count(int state) {
		if (st[state].vis) {
			return st[state].path;
		}
		st[state].vis = true;

		st[state].path = 1;
		for (auto p : st[state].next) {
			st[state].path += count(p.second);
		}

		return st[state].path;
	}
};

SuffixAutomaton sa;

bool solve() {
	cin >> s1 >> s2;

	sa.rebuild(s1);
	int c1 = sa.count(0);

	sa.rebuild(s2);
	int c2 = sa.count(0);

	return c1 == c2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		if (solve()) {
			cout << "s\n";
		}
		else {
			cout << "n\n";
		}
	}

	return 0;
}
