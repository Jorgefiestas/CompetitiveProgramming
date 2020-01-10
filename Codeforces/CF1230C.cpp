#include <bits/stdc++.h>
using namespace std;
int n, m, color[10];
bool vis[10][10];
vector<int> adjList[10];

bool notVis(int a, int b){
	if(a > b)
		return !vis[a][b];
	return !vis[b][a];
}

void setVis(int a, int b, bool v){
	if(a > b)
		vis[a][b] = v;
	else
		vis[b][a] = v;
}

int all_states(int v){

	if(v == n + 1)
		return 0;

	int ans = 0;

	for(int i = 0; i < 7; i++){
		int temp = 0;
		color[v] = i;
		vector<pair<int, int>> uv;

		for(int u : adjList[v]){
			if(i && color[u]){
				if(notVis(i, color[u])){
					setVis(i, color[u], true);
					uv.push_back(make_pair(i, color[u]));
					temp++;
				}
			}
		}
			
		temp += all_states(v + 1);
		ans = max(ans, temp);

		for(pair<int, int> p : uv){
			setVis(p.first, p.second, false);
		}

	}

	color[v] = 0;

	return ans;
}

int main(){
    cin>>n>>m;

    int a, b;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        adjList[a].emplace_back(b);
        adjList[b].emplace_back(a);
    }

    cout<<all_states(1)<<endl;

    return 0;
}
