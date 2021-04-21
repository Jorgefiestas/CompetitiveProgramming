template <class T>
struct pt {
	T x, y;

	pt operator +(const pt &p) const {
		return {x + p.x, y + p.y};
	}
	pt operator -(const pt &p) const {
		return {x - p.x, y - p.y};
	}
};

ostream& operator<<(ostream &out, pt p) {
	out <<  '(' << pt.x << ',' << pt.y << ')';
}
