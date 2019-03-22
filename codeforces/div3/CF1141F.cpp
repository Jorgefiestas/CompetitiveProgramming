#include <bits/stdc++.h>
using namespace std;
map<int, vector<pair<int,int>>> sbs;
vector<pair<int,int>> sol, temp_sol;
int n, t, arr[1501];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>arr[1];
	for(int i = 2; i<=n; i++)
		cin>>t, arr[i] = arr[i-1] + t;
	for(int l = 1; l<=n; l++)
		for(int r = l; r<=n; r++)
			sbs[arr[r]-arr[l-1]].push_back(make_pair(l,r));
	for(auto it : sbs){
		temp_sol.clear();
		sort(it.second.begin(), it.second.end(), [](pair<int,int> a, pair<int,int> b){ return a.second < b.second;});
		int r = 0;
		for(pair<int, int> p : it.second){
			if(p.first <= r) continue;
			r = p.second;
			temp_sol.emplace_back(p);
		}
		if(temp_sol.size() > sol.size()) sol = temp_sol;
	}
	cout<<sol.size()<<endl;
	for(pair<int, int> p : sol)
		cout<<p.first<<" "<<p.second<<endl;
	return 0;
}
