#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
bool rem[N], notPrime[N];
vector<int> primes;
 
int queryA(int x) {
	cout << "A " << x << endl;
	int ans;
	cin >> ans;
	return ans;
}
 
int queryB(int x) {
	cout << "B " << x << endl;
	int ans;
	cin >> ans;
	return ans;
}
 
void sieve() {
	for (int i = 2; i * i < N; i++) {
		if (notPrime[i]) continue;
		for (int j = i * i; j < N; j += i) {
			notPrime[j] = true;
		}
	}
 
	for (int i = 2; i < N; i++) {
		if (notPrime[i]) continue;
		primes.push_back(i);
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	sieve();
 
	cin >> n;
 
	vector<int> factors;
	int cnt = n;
	bool fp = false;
 
	for (int i = 0; i < primes.size(); i++) {
		if (primes[i] > n || (i && i % 100 == 0 && !fp)) {
			int q1 = queryA(1);
			if (q1 != cnt) {
				for (int j = max(0, i - 100); j < i; j++) {
					int q2 = queryA(primes[j]);
					if (!q2) continue;
					factors.push_back(primes[j]);
					break;
				}
				fp = true;
			}
		}
 
		if (primes[i] > n) break;
 
		int p = primes[i];
		int q = queryB(p);
 
		int r = 0;
		for (int j = p; j <= n; j += p) {
			if (rem[j]) continue;
			rem[j] = true;
			r++;
		}
 
		if (r != q) {
			factors.push_back(p);
		}
		cnt -= r;
	}
 
	int x = 1;
	for (int d : factors) {
		x *= d;
		while (x <= n / d && queryA(x * d)) {
			x *= d;
		}
	}
 
	cout << "C " << x << endl;
 
	return 0;
}
