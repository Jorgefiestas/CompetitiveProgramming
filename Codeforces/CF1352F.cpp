#include <bits/stdc++.h>
using namespace std;
int t, n1, n2, n3;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n1 >> n2 >> n3;

		string str;
		for (int i = 0; i < n1; i++) {
			if (str.empty()) {
				str += '0';
			}
			str += '0';
		}

		if (n2) {
			if(str.empty()) {
				str += '0';
			}
			str += '1';
			n2--;
		}

		for (int i = 0; i < n3; i++) {
			if (str.empty()) {
				str += '1';
			}
			str += '1';
		}

		for (int i = 0; i < n2; i++) {
			if (str.back() == '0') {
				str += '1';
			}
			else {
				str += '0';
			}
		}

		cout << str << '\n';
	}

	return 0;
}
