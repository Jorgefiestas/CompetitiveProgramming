#include <bits/stdc++.h>
using namespace std;
int n, wtcnt, blckcnt;
char flp;
string block;
vector<int> moves;

void flip(int i) {
	block[i] = (block[i] == 'W') ? 'B' : 'W';
	i++;
	block[i] = (block[i] == 'W') ? 'B' : 'W';
}

int main() {
	cin >> n >> block;
	
	for (char c : block) {
		if (c == 'W') 
			wtcnt++;
		else
			blckcnt++;
	}

	if (wtcnt % 2 && blckcnt % 2) {
		cout << -1 << endl;
		return 0;
	}

	flp = (wtcnt % 2 == 0) ? 'W' : 'B';

	int i = 0;
	int j = n - 1;
	while (i <= j) {
		while (i <= j && block[i] != flp) {
			i++;
		}
		if (i > j) break;

		moves.push_back(i + 1);
		flip(i);
		i++;
		
		while (i <= j && block[j] != flp) {
			j--;
		}
		if (i > j) break;

		moves.push_back(j);
		flip(j - 1);
		j--;
	}

	cout << moves.size() << endl;
	for (int x : moves) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
