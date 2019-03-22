#include <bits/stdc++.h>
using namespace std;
int n, k, lv, rv, lh ,rh, h;
string a;
vector<int> ltree;
vector<int> rtree;
vector<int> path;
bool vis[1501];

int height(int V){
	int ans = 0;
	int x = V*(k-1)+1;
	while(x > 1){
		x/=k;
		ans++;
	}
	return ans;
}

bool query(int x, int y, int z){
	cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
	cout.flush();
	cin>>a;
	return a == "Yes";
}

void marked(vector<int> &arr){
	for(int x : arr)
		vis[x] = true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	lv = 1;
	rv = n;
	h = height(n);
	while(lh+path.size()+rh != 2*h-1 || ltree.size() > n/2 || rtree.size() > n/2){
		ltree.clear(); rtree.clear(); path.clear();
		while(vis[lv]) lv++;
		vis[lv] = true;
		ltree.emplace_back(lv); rtree.emplace_back(rv);
		for(int i = 1; i < n; i++){
			if(i == lv) continue;
			if(query(lv,i,rv)) path.emplace_back(i);
			else if(query(lv,rv,i)) rtree.emplace_back(i);
			else if(query(rv,lv,i)){
			    if(vis[i]) break;
			    ltree.emplace_back(i);
			}
		}
		lh = height(ltree.size());
		rh = height(rtree.size());
		if(ltree.size() == ((n-1)/k)*(k-1) + 1){ cout<<"! "<<lv<<endl; return 0;}
		if(rtree.size() == ((n-1)/k)*(k-1) + 1){ cout<<"! "<<rv<<endl; return 0;}
		if(ltree.size() < rtree.size()) marked(ltree);
		else marked(rtree);
	}

	sort(path.begin(), path.end(), [](int u, int v){return query(lv, u, v);});
	int i;
	for(i = 0; i + lh + 1 < h; i++);
	cout<<"! "<<path[i]<<endl;
}
