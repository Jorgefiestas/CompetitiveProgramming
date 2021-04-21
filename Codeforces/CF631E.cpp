#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int N = 2e5 + 10;
int n;
long long a[N], s[N];
 
struct Sol {
	long long m, c;
 
	long long eval(long long x) const {
		return m * x + c;
	}
 
	ld cut(const Sol& eq) const {
		return (ld) (eq.c - c) / (m - eq.m);
	}
};
 
long long eval(const deque<Sol> &dq, long long x) {
	int l = 0;
	int r = dq.size() - 1;
 
	while (l < r) {
		int m = (l + r) / 2;
		ld inter = dq[m].cut(dq[m + 1]);
 
		if (inter >= x) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
 
	return dq[l].eval(x);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
 
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += i * a[i];
		s[i] = s[i - 1] + a[i];
	}
 
	deque<Sol> dq;
	long long best = 0;
 
	for (int i = 1; i <= n; i++) {
		Sol eq = {i, -s[i - 1]};
 
		int sz = dq.size();
		while (sz > 1 && dq[sz - 2].cut(eq) < dq[sz - 2].cut(dq[sz - 1])) {
			dq.pop_back();
			sz--;
		}
 
		dq.push_back(eq);
 
		long long ki = s[i - 1] - a[i] * i;
		best = max(best, ki + eval(dq, a[i]));
	}
 
	dq.clear();
 
	for (int i = n; i > 0; i--) {
		Sol eq = {i, -s[i]};
 
		int sz = dq.size();
		while (sz > 2 && eq.cut(dq[1]) < eq.cut(dq[0])) {
			dq.pop_front();
			sz--;
		}
 
		dq.push_front(eq);
 
		long long ki = s[i] - a[i] * i;
		best = max(best, ki + eval(dq, a[i]));
	}
 
 
	cout << sum + best << '\n';
 
	return 0;
}

