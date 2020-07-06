struct Zeta {
	int z[N];

	Zeta(const string &str) {
		memset(z, 0, sizeof z);
		int l = 0, r = 0;
		for (int i = 1; i < str.size(); i++) {
			if (i <= r) {
				z[i] = min(r - i + 1, z[i - l]);
			}
			while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]]) {
				z[i]++;
			}
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}
	}

	int operator[](int idx) {
		return z[idx];
	}
};
