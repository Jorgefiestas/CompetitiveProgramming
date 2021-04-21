#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n;
long long pwr = 0;

struct topSum {
	set<int> st;
	set<int> free;
	long long sum = 0;
	int k = 0;

	void add(int x) {
		sum += (long long) x;
		st.insert(x);

		if (st.size() > k) {
			int mn = *st.begin();
			st.erase(mn);
			free.insert(mn);
			sum -= (long long) mn;
		}
	}

	void del(int x) {
		if (!st.count(x)) {
			free.erase(x);
			return;
		}

		st.erase(x);
		sum -= x;

		if (!free.empty()) {
			int mx = *prev(free.end());
			st.insert(mx);
			free.erase(mx);
			sum += (long long) mx;
		}
	}

	void incCap() {
		k += 1;
		if (!free.empty()) {
			int mx = *prev(free.end());
			st.insert(mx);
			free.erase(mx);
			sum += (long long) mx;
		}
	}

	void redCap() {
		k -= 1;
		if (st.size() > k) {
			int mn = *st.begin();
			st.erase(mn);
			free.insert(mn);
			sum -= (long long) mn;
		}
	}
};

topSum dob;

set<int> light;

void addLight(int d) {
	light.insert(d);
	dob.incCap();

	if (light.size() > 1 && d == *light.begin()) {
		dob.add(*next(light.begin()));
	}
	else if (light.size() > 1) {
		dob.add(d);
	}
}

void remLight(int d) {
	dob.redCap();

	if (d == *light.begin()) {
		light.erase(d);
		if (!light.empty()) {
			dob.del(*light.begin());
		}
	}
	else {
		light.erase(d);
		dob.del(d);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int tp, d;
	for (int i = 0; i < n; i++) {
		cin >> tp >> d;
		pwr += (long long) d;

		if (d > 0) {
			if (tp == 0) {
				dob.add(d);
			}
			else {
				addLight(d);
			}
		}
		else {
			d = -d;
			if (tp == 0) {
				dob.del(d);
			}
			else {
				remLight(d);
			}
		}

		cout << pwr + dob.sum << '\n';
	}

	return 0;
}
