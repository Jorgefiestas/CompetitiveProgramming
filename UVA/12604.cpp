#include <bits/stdc++.h>
using namespace std;
int n, t;
string w, s, alph;
map<char, char> shift;

struct PrefixAutomaton {
	vector<map<char, int>> a;
	vector<int> p;

	void build(const string &str) {
		a.resize(str.size() + 100);
		p.resize(str.size() + 100);

		for (int i = 1; i < str.size(); i++) {
			int j = p[i - 1];
			while (j > 0 && str[i] != str[j]) {
				j = p[j - 1];
			}
			if (str[i] == str[j]) {
				j++;
			}
			p[i] = j;
		}

		for (int state = 0; state < str.size(); state++) {
			a[state][str[state]] = state + 1;
		}
	}

	int go(int state, char c) {
		if (!a[state].count(c)) {
			a[state][c] = state ? go(p[state - 1], c) : 0;
		}
		return a[state][c];
	}
};


void shiftStr(string &str) {
	for (char &c : str) {
		c = shift[c];
	}
}

void solve() {
	cin >> alph >> w >> s;
	n = alph.size();

	for (int i = 0; i < n - 1; i++) {
		shift[alph[i]] = alph[i + 1];
	}
	shift[alph[n - 1]] = alph[0];

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		PrefixAutomaton pa;
		pa.build(w);

		int occ = 0;
		int state = 0;
		for (char c : s) {
			state = pa.go(state, c);
			if (state == w.size()) {
				occ++;
			}
		}
		if (occ == 1) {
			ans.emplace_back(i);
		}
		shiftStr(w);

	}

	if (ans.size() == 0) {
		cout << "no solution\n";
		return;
	}

	if (ans.size() == 1) {
		cout << "unique:";
	}
	else {
		cout << "ambiguous:";
	}

	for (int x : ans) {
		cout << ' ' << x;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		shift.clear();
		solve();
	}

	return 0;
}
