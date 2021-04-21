#include <bits/stdc++.h>
using namespace std;
const int N = 15;
const int M = 3e5 + 10;
const int mod = 998244353;
int fact[M], invfact[M];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int exp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int inv(int x) {
	return exp(x, mod - 2);
}

int choose(int x, int y) {
	if (y < 0 || y > x)
		return 0;
	int den = mul(invfact[y], invfact[x - y]);
	return mul(fact[x], den); 
}

int generator(int p) {
	int phi = p -1;
	int n = phi;

	vector<int> fact;
	for (int i = 2; i * i <= n; i++) {
		if (n % i) continue;
		fact.push_back(i);
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n > 1)
		fact.push_back(n);

	for (int res = 2; res <= p; res++) {
		bool ok = true;
		for (int pf : fact) {
			ok = ok && exp(res, phi / pf) != 1;
			if (!ok) break;
		}

		if (ok) return res;
	}
	return -1;
}

struct NNT {
	int n, root, root_1, root_pw;

	NNT(int n) {
		// p = c * 2^k + 1
		int g = generator(mod);
		root_pw = (1 << n);
		assert((mod - 1) % root_pw == 0);
		root = exp(g, (mod - 1) / root_pw);
		root_1 = inv(root);
	}

	void nnt(vector<int> &a, bool invert) {
		n = a.size();

		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;

			for (; j & bit; bit >>= 1) {
				j ^= bit;
			}

			j ^= bit;

			if (i < j) {
				swap(a[i], a[j]);
			}
		}

		for (int len = 2; len <= n; len <<= 1) {
			int wlen = invert ? root_1 : root;
			for (int i = len; i < root_pw; i <<= 1) {
				wlen = mul(wlen, wlen);
			}

			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j  < len / 2; j++) {
					int u = a[i + j];
					int v = mul(a[i + j + len / 2], w);

					a[i + j] = add(u, v);
					a[i + j + len / 2] = sub(u, v);
					w = mul(w, wlen);
				}
			}
		}

		if (invert) {
			int n_1 = inv(n);
			for (int & x : a) {
				x = mul(x, n_1);
			}
		}
	}
};

NNT fft(N);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	invfact[0] = 1;
	for (int i = 1; i < M; i++) {
		fact[i] = mul(fact[i - 1], i);
		invfact[i] = inv(fact[i]);
	}

	int n;
	cin >> n;

	vector<int> cnt(1 << N, 0);
	cnt[0] = 1;

	int sz = 1;

	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;

		vector<int> comb(1 << N, 0);
		for (int j = b - sz + 1; j < sz + a; j++) {
			comb[j - b + sz - 1] = choose(a + b, j);
		}

		fft.nnt(cnt, false);
		fft.nnt(comb, false);

		for (int j = 0; j < (1 << N); j++) {
			cnt[j] = mul(comb[j], cnt[j]);
		}

		fft.nnt(cnt, true);

		for (int j = 0; j < (1 << N); j++) {
			if (j < sz + a - b) cnt[j] = cnt[j + sz - 1];
			else cnt[j] = 0;
		}

		sz += a - b;
	}

	int ans = 0;
	for (int i = 0; i < (1 << N); i++) {
		ans = add(ans, cnt[i]);
	}

	cout << ans << '\n';

	return 0;
}
