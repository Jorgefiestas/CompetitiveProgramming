#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int P = 1.3e6;
const int mod = 998244353;
int n;
vector<long long> large;
map<long long, int> cnt;
map<long long, int> lngcnt;
bool fact[N];

long long gcd(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

long long root(long long x, long long k) {
	long long l = 1; 
	long long r;
	if (k == 2) {
		r = 1500000000;
	}
	else if (k == 3) {
		r = 1500000;
	}
	else {
		r = 32000;
	}

	while (l <= r) {
		long long m = (l + r) / 2;
		long long p  = 1;
		for (int i = 0; i < k; i++) {
			p *= m;
		}

		if (p == x) {
			return m;
		}
		
		if (p < x) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return -1;
}

void count(long long x) {
	long long fr = root(x, 4);
	if (fr != -1) {
		cnt[fr] += 4;
		return;
	}

	long long cr = root(x, 3);
	if (cr != -1) {
		cnt[cr] += 3;
		return;
	}

	long long sr = root(x, 2);
	if (sr != -1) {
		cnt[sr] += 2;
		return;
	}

	large.emplace_back(x);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		count(a);
	}

	for (auto p : cnt) {
		for (int i = 0; i < large.size(); i++) {
			if (fact[i] || large[i] % p.first) continue;
			cnt[p.first]++;
			cnt[large[i] / p.first]++;
			fact[i] = true;
		}
	}

	for (int i = 0; i < large.size(); i++) {
		if (fact[i]) continue;
		for (int j = 0; j < large.size(); j++) {
			if (large[i] == large[j]) continue;
			long long g = gcd(large[i], large[j]);
			if (g != 1) {
				cnt[g]++;
				cnt[large[i] / g]++;
				fact[i] = true;
				break;
			}
		}
	}

	for (int i = 0; i < large.size(); i++) {
		if (fact[i]) continue;
		lngcnt[large[i]]++;
	}

	int ans = 1;
	for (auto p : cnt) {
		ans = (long long) ans * (p.second + 1) % mod;
	}

	for (auto p : lngcnt) {
		ans = (long long) ans * (p.second + 1) % mod;
		ans = (long long) ans * (p.second + 1) % mod;
	}

	cout << ans << '\n';
	
	return 0;
}
