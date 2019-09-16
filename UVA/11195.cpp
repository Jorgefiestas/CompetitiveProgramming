#include <bits/stdc++.h>
using namespace std;
int r;
bool vis[10][10];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int paths(int x, int y){
	if(x >= 10 || y >= 10 || x < 0 || y < 0) return 0; 	
	if(vis[x][y]) return 0;
	vis[x][y] = true;
	int w = 0;
	for(int i = 0; i<8; i++)
		w = max(w, paths(x + dx[i], y + dy[i]));
	vis[x][y] = false;
	return w + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ca = 1;
	while(cin>>r, r){
		memset(vis, true, sizeof vis);
		int x, c = 0;
		for(int i = 0; i<r; i++){
			int l, ri;
			cin>>l>>ri;
			if(i == 0) x = l;
			c += ri;
			for(int j = 0; j<ri; j++) vis[i][j+l] = false;
		}
		int d = c-paths(0, x);
		if(d == 1) cout<<"Case "<<ca<<", 1 square can not be reached."<<endl;
		else cout<<"Case "<<ca<<", "<<c-paths(0, x)<<" squares can not be reached."<<endl;
		ca++;
	}
	return 0;
}
