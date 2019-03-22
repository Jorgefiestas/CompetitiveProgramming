#include <bits/stdc++.h>
using namespace std;
int n, t;
vector<vector<int>> arr(2001, vector<int>(3));
vector<int> sol;
unordered_map<int, bool> mem;

bool check(int k){
	if(mem.find(k) != mem.end()) return mem[k];
	mem[k] = false;
	sol.clear();
	int temp_t = 0;
	for(vector<int> x : arr){
		if(k > x[1]) continue;
		temp_t += x[2];
		if(temp_t > t) return false;
		sol.emplace_back(x[0]);
		if(sol.size() == k) break;
	}
	mem[k] = sol.size() == k;
	return mem[k];
}

int bs(){
	if(check(n)) return n;
	int l = 1, r = n-1, m = (l+r)/2;
	while(l<r){
		if(!check(m+1) && check(m)) return m;
		if(mem[m]) l = m;
		else r = m-1;
		m = (l+r)/2;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>t;
	arr.resize(n);
	for(int i = 0; i<n; i++)
		cin>>arr[i][1]>>arr[i][2], arr[i][0] = i + 1;
	sort(arr.begin(), arr.begin() + n, [](vector<int> a, vector<int> b){ return a[2] < b[2]; });
	cout<<sol.size()<<endl;
	cout<<sol.size()<<endl;
	for(int x : sol)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
