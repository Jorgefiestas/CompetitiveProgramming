#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
pii st[400050];
int n, q, arr[100005];

pii maxPair(pii a, pii b){
	pii ans;
	
	if (a.first > b.first) {
		ans.first = a.first;
		if (a.second > b.first) {
			ans.second = a.second;
		}
		else {
			ans.second = b.first;
		}
	}
	else {
		ans.first = b.first;
		if (b.second > a.first) {
			ans.second = b.second;
		}
		else {
			ans.second = a.first;
		}
	}
	return ans;
}

void build(int v, int l, int r) {
	if (l == r) {
		st[v] = {arr[l], 0};
	}
	else {
		int m = (r + l) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		st[v] = maxPair(st[v * 2], st[v * 2 + 1]);
	}
}

pii query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return {0, 0};
	}
	if (tl == l && tr == r) {
		return st[v];
	}
	int tm = (tr + tl) / 2;
	pii ql = query(v * 2, tl, tm, l, min(r, tm));
	pii qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	return maxPair(ql, qr);
}

void update(int v, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        st[v] = {val, 0};
    }
	else {
        int tm = (tl + tr) / 2;

        if (idx <= tm) {
            update(v * 2, tl, tm, idx, val);
		}
        else {
            update(v * 2 + 1, tm + 1, tr, idx, val);
		}

        st[v] = maxPair(st[2 * v], st[2 * v + 1]);
    }
}
	
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	build(1, 0, n - 1);

	cin >> q;
	char c;
	int l, r;
	pii qans;
	for (int i = 0; i < q; i++) {
		cin >> c >> l >> r;
		if (c == 'U') {
			update(1, 0, n - 1, l - 1, r);
		}
		else {
			qans = query(1, 0, n - 1, l - 1, r - 1);
			cout << qans.first + qans.second << '\n';
		}
	}
	return 0;
}
