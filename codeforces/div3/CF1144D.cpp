#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> cnt;
deque<string> q;
long long n, arr[200000], mx;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++)
		cin>>arr[i], cnt[arr[i]]++;
	mx = arr[0];
	for(auto it : cnt)
		if(it.second > cnt[mx]) mx = it.first;
	bool state=true;
	for(int i = 0; i<n; i++){
		if(arr[i] == mx){
			state = false;
			continue;
		}
		int op = (arr[i]>mx) + 1;
		string ope = to_string(op) + " " + to_string(i+1) + " " + to_string(i + 2*state);
		if(state) q.push_front(ope);
		else q.push_back(ope);
	}
	cout<<q.size()<<endl;
	while(!q.empty())
		cout<<q.front()<<endl, q.pop_front();
	return 0;
}
