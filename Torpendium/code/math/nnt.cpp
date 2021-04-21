// Include modularops and generator

struct NNT {
	int n, root, root_1, root_pw;
 
	NNT(int n) {
		// mod = c * 2^k + 1
		int g = generator(mod);
		root_pw = (1 << n);
		assert((mod - 1) % root_pw == 0);
		root = exp(g, (mod - 1) / root_pw);
		root_1 = inv(root);
	}
 
	void nnt(vector<int> &a, bool invert) {
		n = a.size();
 
		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
 
			for (; j & bit; bit >>= 1) {
				j ^= bit;
			}
 
			j ^= bit;
 
			if (i < j) {
				swap(a[i], a[j]);
			}
		}
 
		for (int len = 2; len <= n; len <<= 1) {
			int wlen = invert ? root_1 : root;
			for (int i = len; i < root_pw; i <<= 1) {
				wlen = mul(wlen, wlen);
			}
 
			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j  < len / 2; j++) {
					int u = a[i + j];
					int v = mul(a[i + j + len / 2], w);
 
					a[i + j] = add(u, v);
					a[i + j + len / 2] = sub(u, v);
					w = mul(w, wlen);
				}
			}
		}
 
		if (invert) {
			int n_1 = inv(n);
			for (int & x : a) {
				x = mul(x, n_1);
			}
		}
	}
};
