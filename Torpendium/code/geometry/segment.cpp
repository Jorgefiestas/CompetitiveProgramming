struct Seg {
	pt a, b;

	ld dist(const pt &p) const {
		pt ab = b - a;
		pt bp = p - b;
		pt ap = p - a;

		if (ab.dot(bp) > 0) {
			return bp.arg();
		}
		if (ab.dot(ap) < 0) {
			return ap.arg();
		}
		return ab.cross(ap) / ab.arg();
	}

	ld len() {
		return (a - b).arg();
	}
};
