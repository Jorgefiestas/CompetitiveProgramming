#include <bits/stdc++.h>
using namespace std;
using pii = pair<int ,int>;
string str;
vector<pii> blocks;

vector<pii> compress(vector<pii> &arr) {
	int n = arr.size();
	vector<pii> narr;
	vector<pii> ans;

	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			arr[i].first -= 1;
		}
		if (arr[i].first) {
			narr.push_back(arr[i]);
		}

		int j = i + 1;
		while (j < n && arr[j].first == 1) {
			j += 1;
		}

		arr[j].first -= 1;
		i = j - 1;
	}

	for (auto [cnt, col] : narr) {
		if (ans.empty() || ans.back().second != col) {
			ans.push_back({cnt, col});
		}
		else {
			ans.back().first += cnt;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		int j = i + 1;
		while (j < str.size() && str[j] == str[i]) {
			j += 1;
		}
		blocks.push_back({j - i, str[i] - 'a'});
		i = j - 1;
	}

	int cnt = 0;
	while (blocks.size() > 1) {
		blocks = compress(blocks);
		cnt += 1;
	}

	cout << cnt << '\n';

	return 0;
}
