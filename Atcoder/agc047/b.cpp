#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n;
string str[N];

int trie[10 * N][26], cnt[10 * N][26];
bool term[10 * N];
int nodecnt = 1;
void add(const string &s) {
	int node = 0;
	for (int i = 0; i < s.size(); i++) {
		int idx = s[i] - 'a';

		if (i == s.size() - 1) {
			cnt[node][idx] += 1;
		}

		if (!trie[node][idx]) {
			trie[node][idx] = nodecnt++;
		}
		node = trie[node][idx];
	}
}

int query(const string &s) {
	int scnt[26];
	memset(scnt, 0, sizeof scnt);

	for (char c : s) {
		scnt[c - 'a'] += 1;
	}

	int node = 0;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int idx = s[i] - 'a';

		for (int j = 0; j < 26; j++) {
			if (!scnt[j]) continue;
			ans += cnt[node][j];
		}

		scnt[idx] -= 1;
		if (!trie[node][idx]) {
			break;
		}
		node = trie[node][idx];
	}

	return ans;
}

bool comp(const string &a, const string &b) {
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		reverse(str[i].begin(), str[i].end());
	}

	sort(str, str + n, comp);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (long long) query(str[i]);
		add(str[i]);
	}

	cout << ans << '\n';

	return 0;
}
