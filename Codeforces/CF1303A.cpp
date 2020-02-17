#include <bits/stdc++.h>
using namespace std;
int t, z, zo;
string str;

int main() {
	cin >> t;

	while (t--) {
		z = 0;
		zo = 0;

		cin >> str;

		bool seenOne = false;
		for (char c : str) {
			if (!seenOne && c != '1') {
				continue;
			}
			else if (!seenOne && c == '1') {
				seenOne = true;
			}
			else if (c == '0') {
				z++;
				zo++;
			}
			else {
				zo = 0;
			}
		}

		cout << z - zo << '\n';
	}

	return 0;
}
