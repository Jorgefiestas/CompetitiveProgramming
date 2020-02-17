#include <bits/stdc++.h>
using namespace std;
int T, h, w;
int mat[100][100], mem[100][100];
bool vis[100][100];

int dp(int x, int y){
    if(y == h) return 0;
    if(vis[x][y]) return mem[x][y];
    vis[x][y] = true;
    int ans = dp(x, y+1);
    if(x > 0) ans = max(ans, dp(x-1, y+1));
    if(x < w-1) ans = max(ans, dp(x+1, y+1));
    return mem[x][y] = ans + mat[y][x];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--){
        memset(mat, 0, sizeof mat);
        memset(mem, 0, sizeof mem);
        memset(vis, false, sizeof vis);
        cin>>h>>w;
        for(int i = 0; i<h; i++)
            for(int j = 0; j<w; j++)
                cin>>mat[i][j];
        int res = 0;
        for(int i = 0; i<w; i++)
            res = max(res, dp(i, 0));
        cout<<res<<endl;
    }
    return 0;
}
