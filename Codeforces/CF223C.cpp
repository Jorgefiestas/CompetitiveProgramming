#include <bits/stdc++.h>
using namespace std;

struct node {
	int l = 0;
	int o = 0;
	int c = 0;
};

string str;
int m;
node st[4000005];

void merge(node &n1, node &n2, node &n3) {
	int b = min(n2.o, n3.c);
	n1.o = n2.o + n3.o - b;
	n1.c = n2.c + n3.c - b;
	n1.l = n2.l + n3.l + 2 * b;
}

void build(int v, int l, int r) {
	if (l == r) {
		if(str[l] == '(') {
			st[v].o++;
		}
		else {
			st[v].c++;
		}
	}
	else {
		int m = (r + l) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		merge(st[v], st[v * 2], st[v * 2 + 1]);
	}
}

node query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		node em;
		return em;
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int tm = (tr + tl) / 2;
	node ql = query(v * 2, tl, tm, l, min(r, tm));
	node qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	node ans;
	merge(ans, ql, qr);
	return ans;
}

int main() {
	cin >> str;

	build(1, 0, str.size() - 1);

	cin >> m;
	int l, r;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		node qans = query(1, 0, str.size() - 1, l - 1, r - 1);
		cout << qans.l << endl;
	}

	return 0;
}
