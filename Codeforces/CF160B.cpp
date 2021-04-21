#include <bits/stdc++.h>
using namespace std;
int n;
string num;

bool check(string &str) {
	string front, back;

	for (int i = 0; i < 2 * n; i++) {
		if (i < n) {
			front += str[i];
		}
		else {
			back += str[i];
		}
	}
	sort(front.begin(), front.end());
	sort(back.begin(), back.end());

	for (int i = 0; i < n; i++) {
		if (front[i] >= back[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> num;

	bool val = check(num);
	reverse(num.begin(), num.end());
	val = val || check(num);

	if (val) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
