#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int t, cnt[N];
string str;

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

int solve() {
	cin >> str;

	int ans  = 0;

	string pat = str;

	while (!pat.empty()) {
		PrefixAutomaton pa;
		pa.build(pat);
		memset(cnt, 0, sizeof cnt);

		int state = 0;
		for (char c : str) {
			state = pa.go(state, c);
			cnt[state]++;
		}

		for (int i = pat.size(); i > 0; i--) {
			cnt[pa.p[i]] += cnt[i];
		}

		for (int i = pat.size(); i > 0; i--) {
			if (cnt[i] < 2) continue;
			ans = max(ans, i);
			break;
		}

		pat.erase(pat.begin());
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}
	
	return 0;
}
