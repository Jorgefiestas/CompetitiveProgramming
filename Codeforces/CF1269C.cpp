#include <bits/stdc++.h>
using namespace std;
int n, k;
string num;
 
int main() {
	cin >> n >> k;
	cin >> num;

	bool grt = false;
	bool smllr = false;

	for (int i = 0; i < n - k; i++) {
		if (num[i + k] < num[i]) {
			grt = true;
		}
		else if (num[i + k] > num[i] && !grt) {
			smllr = true;
		}
		num[i + k] = num[i];
	}

	if (smllr) {
		for (int i = k - 1; i >= 0; i--) {
			if (num[i] != '9') {
				num[i]++;
				break;
			}
			num[i] = '0';
		}
		for (int i = 0; i < n - k; i++) {
			num[i + k] = num[i];
		}
	}

	cout << n << endl;
	cout << num << endl;
 
	return 0;
}
