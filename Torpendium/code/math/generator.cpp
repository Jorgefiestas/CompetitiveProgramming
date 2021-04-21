// Include modular ops

int generator(int p) {
	int phi = p -1;
	int n = phi;
 
	vector<int> fact;
	for (int i = 2; i * i <= n; i++) {
		if (n % i) continue;
		fact.push_back(i);
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n > 1)
		fact.push_back(n);
 
	for (int res = 2; res <= p; res++) {
		bool ok = true;
		for (int pf : fact) {
			ok = ok && exp(res, phi / pf) != 1;
			if (!ok) break;
		}
 
		if (ok) return res;
	}
	return -1;
}
