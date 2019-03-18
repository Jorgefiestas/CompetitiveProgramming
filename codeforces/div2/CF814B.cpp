#include <bits/stdc++.h>
using namespace std;
unordered_set<int> st;
int n, a[1000], b[1000], c[1000];
vector<int> d;

void swap(int* x, int*y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

bool check(int* x, int* y, int n){
	bool ch = false;
	for(int i = 0; i<n; i++){
		if(x[i] == y[i]) continue;
		if(ch) return false;
		ch = true;
	}
	return ch;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1; i<= n; i++) st.insert(i);
	for(int i = 0; i<n; i++) cin>>a[i];
	for(int i = 0; i<n; i++){
		cin>>b[i];
		if(b[i] == a[i]){
			st.erase(b[i]);
			c[i] = b[i];
		}
		else d.emplace_back(i);
	}
	for(int x : d){
		c[x] = *st.begin();
		st.erase(st.begin());
	}
	if(d.size() > 1)
		if(!check(a, c, n) || !check(b, c, n)) swap(c+d[0], c+d[1]);
	for(int i = 0; i<n; i++)
		cout<<c[i]<<' ';
	cout<<endl;
}
