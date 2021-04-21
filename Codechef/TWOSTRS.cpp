#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int t, n, an, bn;
long long pref[N], suff[N];
string a, b;

struct AhoCorasick {
	int trie[N][26];
	int par[N];
	int tran[N];
	int link[N];
	long long cnt[N];
	long long term[N];
	int nodecnt = 1;
	bool vis[N];

	void clear() {
		memset(trie, -1, sizeof trie);
		memset(link, -1, sizeof link);
		memset(cnt, -1, sizeof cnt);
		memset(term, 0, sizeof term);
		memset(vis, 0, sizeof vis);
	}

	void insert(const string &str, long long val) {
		int node = 0;
		for (char c : str) {
			int i = c - 'a';
			if (trie[node][i] == -1) {
				tran[nodecnt] = c;
				par[nodecnt] = node;
				trie[node][i] = nodecnt++;
			}
			node = trie[node][i];
		}
		term[node] += val;
	}

	int getLink(int node) {
		if (link[node] == -1) {
			if (!node || !par[node]) {
				return link[node] = 0;
			}
			return link[node] = go(getLink(par[node]), tran[node]);
		}
		return link[node];
	}

	int go(int node, char c) {
		int i = c - 'a';
		if (trie[node][i] == -1) {
			trie[node][i] = node ? go(getLink(node), c) : 0;
		}
		return trie[node][i];
	}

	long long count(int node) {
		if (cnt[node] != -1) {
			return cnt[node];
		}

		cnt[node] = term[node];
		cnt[node] += count(getLink(node));
		return cnt[node];
	}
};

AhoCorasick ac;

long long count(string &s, int l, int r) {
	long long ans = 0;

	int st = 0;
	for (int i = l; i <= r; i++) {
		st = ac.go(st, s[i]);
		ans += ac.count(st);
	}

	return ans;
}

string substring(const string &str, int l, int r) {
	string ans;

	for (int i = l; i <= r; i++) {
		ans += str[i];
	}
	return ans;
}

long long solve() {
	cin >> a >> b >> n;
	an = a.size();
	bn = b.size();

	string si;
	int bi;
	for (int i = 0; i < n; i++) {
		cin >> si >> bi;
		ac.insert(si, bi);
	}

	for (int j = 0; j < bn; j++) {
		suff[j] = count(b, j, bn - 1) - count(b, j, min(j + 30, bn - 1));
	}

	long long pref = 0;
	long long ans = 0;

	int st = 0;
	for (int i = 0; i < an; i++) {
		st = ac.go(st, a[i]);
		pref += ac.count(st);

		for (int j = 0; j < bn; j++) {
			string temp;
			temp += substring(a, max(0, i - 30), i);
			temp += substring(b, j, min(j + 30, bn - 1));
			ans = max(ans, pref[i] + suff[j] + count(temp, 0, temp.size() - 1));
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		ac.clear();
		cout << solve() << '\n';
	}

	return 0;
}
