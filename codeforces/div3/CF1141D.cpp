#include <bits/stdc++.h>
using namespace std;
int n;
string l, r;
map<char, stack<int>> lc, rc;
bool lvis[150001], rvis[150001];
vector<vector<int>> sol;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>l>>r;
	for(int i = 0; i<n; i++)
		lc[l[i]].push(i+1);
	for(int i = 0; i<n; i++)
		rc[r[i]].push(i+1);
	for(auto it : lc){
		if(it.first == '?') continue;
		while(!it.second.empty()&& !rc[it.first].empty()){
			sol.push_back({it.second.top(), rc[it.first].top()});
			lvis[it.second.top()] = true, rvis[rc[it.first].top()] = true;
			it.second.pop(), rc[it.first].pop();
		}
	}
	if(!lc['?'].empty()){
		for(int i = 0; i<n; i++){
			if(rvis[i+1] || r[i] == '?') continue;
			rvis[i+1] = true;
			sol.push_back({lc['?'].top(), i+1});
			lc['?'].pop();
			if(lc['?'].empty()) break;
		}
	}
	if(!rc['?'].empty()){
		for(int i = 0; i<n; i++){
			if(lvis[i+1] || l[i] == '?') continue;
			lvis[i+1] = true;
			sol.push_back({i+1, rc['?'].top()});
			rc['?'].pop();
			if(rc['?'].empty()) break;
		}
	}
	while(!rc['?'].empty() && !lc['?'].empty()){
		sol.push_back({lc['?'].top(), rc['?'].top()});
		lc['?'].pop(), rc['?'].pop();
	}
	cout<<sol.size()<<endl;
	for(vector<int> x : sol)
		cout<<x[0]<<" "<<x[1]<<endl;
	return 0;
}
