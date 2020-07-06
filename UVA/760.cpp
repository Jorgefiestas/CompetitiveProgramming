#include <bits/stdc++.h>
using namespace std;
const int N = 330;
string a, b;

struct PrefixAutomaton {
	int a[N][26];
	int p[N];

	PrefixAutomaton() {
		memset(p, 0, sizeof p);
		memset(a, -1, sizeof a);
	}

	void build(const string &str) {
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
			int i = str[state] - 'a';
			a[state][i] = state + 1;
		}
	}

	int go(int state, char c) {
		int i = c - 'a';
		if (a[state][i] == -1) {
			a[state][i] = state ? go(p[state - 1], c) : 0;
		}
		return a[state][i];
	}
};

void solve() {
	vector<string> matches;

	while(!a.empty()) {
		PrefixAutomaton pa;
		pa.build(a);
		
		int state = 0;
		int mx = 0;
		for (char c : b) {
			state = pa.go(state, c);
			mx = max(state, mx);
		}

		if (mx == 0) {
			a.erase(a.begin());
			continue;
		}

		string lstr;
		for (int i = 0; i < mx; i++) {
			lstr += a[i];
		}

		if (!matches.empty() && matches[0].size() < mx) {
			matches.clear();
		}
		if ( matches.empty() || matches[0].size() == mx) {
			matches.emplace_back(lstr);
		}

		a.erase(a.begin());
	}
	
	if (matches.empty()) {
		cout << "No common sequence." << endl;
		return;
	}

	sort(matches.begin(), matches.end());
	matches.erase(unique(matches.begin(), matches.end()), matches.end());

	for (string s : matches) {
		cout << s << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bool first = true;
	while (cin >> a >> b) {
		if (first) {
			first = false;
		}
		else {
			cout << '\n';
		}

		solve();
	}

	return 0;
}
