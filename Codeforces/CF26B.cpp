#include <bits/stdc++.h>
using namespace std;
int cnt, o;
string str;

int main() {
	cin >> str;

	for (char c : str) {
		if (c == '(') {
			o++;
		}
		else if (o) {
			cnt += 2;
			o--;
		}
	}

	cout << cnt << endl;
	return 0;
}
