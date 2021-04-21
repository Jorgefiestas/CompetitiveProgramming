int kmp(const string &str, const string &pat) {
	int n = str.size();
	int m = pat.size();

	vector<int> pref(m + 1);

	pref[0] = -1;
	int j = -1;

	for (int i = 0; i < m; i++) {
		while (j != -1 && pat[i] != pat[j])
			j = pref[j];
		j += 1;
		pref[i + 1] = j;
	}

	for (int i = 0; i < n; i++) {
		while (j != -1 && str[i] != pat[j])
			j = pref[j];
		j += 1;

		if (j == m) {
			// Found Match;
			j = pref[j];
		}
	}

}
