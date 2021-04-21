#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n;
 
bool query(int r1, int c1, int r2, int c2) {
	cout << "? " << r1 << ' ' << c1;
	cout << ' ' << r2 << ' ' << c2 << endl;
 
	string ans;
	cin >> ans;
	return ans == "YES";
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
 
	int x = 1;
	int y = 1;
 
	string front;
 
	vector<pii> positions;
	for (int i = 1; i < n; i++) {
		positions.push_back({x, y});
		if (query(x + 1, y, n, n)) {
			front += 'D';
			x += 1;
		}
		else {
			front += 'R';
			y += 1;
		}
	}
 
	x = n;
	y = n;
 
	string back;
	
	for (int i = 1; i < n; i++) {
		auto [px, py] = positions[n - i - 1];
		if (query(px, py, x, y - 1)) {
			y -= 1;
			back += 'R';
		}
		else {
			x -= 1;
			back += 'D';
		}
	}
 
	reverse(back.begin(), back.end());
	cout << "! " << front + back << '\n';
	
	return 0;
}
