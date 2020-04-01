#include <bits/stdc++.h>
using namespace std;
int n, p;
long long s;
long long arr[200005];
unordered_map<long long, long long> mem;

long long s_k(long long d){
	if(mem.find(d) != mem.end()) return mem[d];
	long long t = 0;
	for(long long i = 0; i<n; i++)
		t += max((long long)0, arr[i] - i/d);
	mem[d] = t;
	return t;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>p;
	for(int i = 0; i<n; i++)
		cin>>arr[i], s+= arr[i];
	if(s<p){
		cout<<-1<<endl;
		return 0;
	}
	if(s == p){
		cout<<n<<endl;
		return 0;
	}
	sort(arr, arr+n, greater<long long>());
	int l = 1, r = n, m=1;
	mem[0] = 0;
	while(l<r){
		m = (l+r)/2;
		if(s_k(m) >= p && s_k(m-1) < p) break;
		else if(s_k(m) < p) l = m;
		else r = m;
	}	
	cout<<m<<endl;
	return 0;
}
