#include <bits/stdc++.h>
using namespace std;
const int N = 19;
const int M = (1 << 19) + 10;
const int h = 5;
const int w[] = {3, 4, 5, 4, 3};
vector<vector<int>> lines;
bool mem[M], vis[M];

const int rot[] = {7, 3, 0, 
					12, 8, 4, 1, 
					16, 13, 9, 5, 2, 
					17, 14, 10, 6, 
					18, 15, 11};

int rotate(int bm) {
	int nbm = 0;
	for (int i = 0; i < N; i++) {
		if (bm & (1 << rot[i])) {
			nbm |= (1 << i);
		}
	}

	return nbm;
}

bool dp(int bm) {
	if (vis[bm]) {
		return mem[bm];
	}
	bool ans = false;
	for (int i = 0; i < 3; i++) {
		for (vector<int> line : lines) {
			bool present = true;
			for (int ch : line) {
				if (bm & (1 << ch)) continue;
				present = false;
				break;
			}

			if (present) {
				int nbm = bm;
				for (int ch : line) {
					nbm ^= (1 << ch);
				}
				if (!dp(nbm)) {
					ans = true;
					break;
				}
			}
		}
		bm = rotate(bm);
	}

	for (int i = 0; i < 6; i++) {
		vis[bm] = true;
		mem[bm] = ans;
		bm = rotate(bm);
	}

	return mem[bm];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c;
	int box = 0;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == 'O') {
			box |= (1 << i);
		}
	}

	int ch = 0;
	for (int i = 0; i < h; i++) {
		int last = ch + w[i];
		for (int j = 0; j < w[i]; j++) {
			vector<int> line;
			for (int k = ch; k < last; k++) {
				line.emplace_back(k);
				lines.push_back(line);
			}
			ch++;
		}
	}

	ch = 0;
	for (int i = 0; i < h; i++) {
		int last = ch + w[i];
		for (int j = 0; j < w[i]; j++) {
			vector<int> line;
			for (int k = ch; k < last; k++) {
				line.emplace_back(k);
				lines.push_back(line);
			}
			ch++;
		}
	}

	if (dp(box)) {
		cout << "Karlsson\n";
	}
	else {
		cout << "Lillebror\n";
	}

	return 0;
}
