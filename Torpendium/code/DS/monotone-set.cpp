//query(Key k) : returns max value with key <= k
//insert(Key k, Value v): inserts a value v with key k

struct MonoSet {
	set<pii> st;

	MonoSet() {
		st.insert({INT_MAX, INT_MIN});
	}

	void add(int x, int y) {
		auto it = st.upper_bound({x, y});

		if (it != st.begin() && prev(it)->second <= v)
			return;

		it = st.insert({x, y}).first;
		while (it->second <= next(it)->second) {
			st.erase(next(it));
		}
	}

	int query(int x) {
		auto it = st.lower_bound({x, INT_MAX});

		if (it == st.begin())
			return -1;
		return prev(it)->second;
	}
};

