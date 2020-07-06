struct Prefix {
	int p[N];

	Prefix() {
		memeset(p, 0, sizeof p);
	}

	void build(const string &str) {
		for (int i = 1; i < str.size(); i++) {
			int j = p[i - 1];
			while (j > 0 && str[i] != str[j]) {
				j = p[j - 1];
			}
			if (str[i] == str[j]) {
				j++;
			}
			p[i] = j;
		}
	}

	int operator [](int idx) {
		return p[idx];
	}
};

struct PrefixAutomaton {
	int a[N][26];
	int p[N];

	PrefixAutomaton() {
		memset(p, 0, sizeof p);
		memset(a, -1, sizeof a);
	}

	void build(const string &str) {
		for (int i = 1; i < str.size(); i++) {
			int j = p[i - 1];
			while (j > 0 && str[i] != str[j]) {
				j = p[j - 1];
			}
			if (str[i] == str[j]) {
				j++;
			}
			p[i] = j;
		}

		for (int state = 0; state < str.size(); state++) {
			int i = str[state] - 'a';
			a[state][i] = state + 1;
		}
	}

	int go(int state, char c) {
		int i = c - 'a';
		if (a[state][i] == -1) {
			a[state][i] = state ? go(p[state - 1], c) : 0;
		}
		return a[state][i];
	}
};
