#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, q;
string str;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

struct Mat { 
	int mat[2][2];

	Mat operator *(const Mat &m) {
		Mat c;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c.mat[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					int p = mul(mat[i][k], m.mat[k][j]);
					c.mat[i][j] = add(c.mat[i][j], p);
				}
			}
		}

		return c;
	}

	pii query(int a, int b) {
		int na = add(mul(mat[0][0], a), mul(mat[1][0], b));
		int nb = add(mul(mat[0][1], a), mul(mat[1][1], b));
		return {na, nb};
	}

	void inv() {
		swap(mat[0][0], mat[1][1]);
		swap(mat[0][1], mat[1][0]);
	}

	static Mat id() {
		Mat i;
		memset(i.mat, 0, sizeof i.mat);
		i.mat[0][0] = 1;
		i.mat[1][1] = 1;
		return i;
	}
};

struct SegTree {
	Mat st[4 * N];
	bool lazy[4 * N];

	void build(int v, int tl, int tr) {
		if (tl == tr) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					st[v].mat[i][j] = 1;
				}
			}

			if (str[tl - 1] == 'A') {
				st[v].mat[0][1] = 0;
			}
			else {
				st[v].mat[1][0] = 0;
			}

			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		st[v] = st[v * 2] * st[v * 2 + 1];
	}


	void push(int v) {
		if (lazy[v]) {
			st[v * 2].inv();
			st[v * 2 + 1].inv();

			lazy[v * 2] = !lazy[v * 2];
			lazy[v * 2 + 1] = !lazy[v * 2 + 1];

			lazy[v] = false;
		}
	}

	Mat query(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return Mat::id();
		}
		if (tl == l && tr == r) {
			return st[v];
		}
		push(v);
		int tm = (tl + tr) / 2;
		Mat ql = query(v * 2, tl, tm, l, min(tm, r));
		Mat qr = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
		return ql * qr;
	}

	void update(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return;
		}
		if (tl == l && tr == r) {
			st[v].inv();
			lazy[v] = !lazy[v];
			return ;
		}
		push(v);
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(tm, r));
		update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
		st[v] = st[v * 2] * st[v * 2 + 1];
	}

};

SegTree st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	cin >> str;

	st.build(1, 1, n);

	int op, l, r, a, b;
	for (int qi = 0; qi < q; qi++) {
		cin >> op;

		if (op == 1) {
			cin >> l >> r;
			st.update(1, 1, n, l, r);
		}
		if (op == 2) {
			cin >> l >> r >> a >> b;
			Mat trn = st.query(1, 1, n, l, r);
			pii ans = trn.query(a, b);
			cout << ans.first << ' '  << ans.second << '\n';
		}
	}

	return 0;
}
