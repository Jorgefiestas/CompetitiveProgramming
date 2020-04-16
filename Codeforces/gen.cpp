#include <bits/stdc++.h>
using namespace std;

int main() {
	ofstream f("in.txt");

	f << 200000 << endl;
	for (int i = 0; i < 200000; i++) {
		f << 166320 << ' ';
	}
	f << endl;
	
	for (int i = 1; i <= 199999; i++) {
		f << i << ' ' << i + 1 << endl;
	}

	f.close();

	return 0;
}

