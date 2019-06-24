#include <bits/stdc++.h>
using namespace std;
int T, w, h, n;
vector<string> grid;

int movesx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int movesy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int mn(int y, int x){
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    vector<vector<int>> dist(h, vector<int>(w, 0));
    int cnt = 0;
    int moves = 0;
    
    queue<pair<int, int>> q;
    
    q.push(make_pair(y, x));
    vis[y][x] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(grid[i][j] > '0' && grid[i][j] <= '9'){
            int k = grid[i][j] - '0';
            moves += (dist[i][j] + k - 1)/k;
            cnt++;
        }
        
        for(int k = 0; k < 8; k++){
            int ti = i + movesy[k];
            int tj = j + movesx[k];

            if(ti < 0 || ti >= h || tj < 0 || tj >= w) continue;
            if(vis[ti][tj]) continue;

            vis[ti][tj] = true;
            dist[ti][tj] = dist[i][j] + 1;

            q.push(make_pair(ti, tj));
        }
    }

    if(cnt == n) return moves;
    
    return -1;
}

int solve(){
    grid.clear();
    n = 0;

    cin>>h>>w;
    grid.resize(h);

    for(int i = 0; i < h; i++){
        cin>>grid[i];
        for(int j = 0; j < w; j++){
            if(grid[i][j] > '0' && grid[i][j] <= '9') n++;
        }
    }

    int cnt = -1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int temp = mn(i, j);
            if(temp >= 0){
                if(cnt == -1) cnt = temp;
                cnt = min(cnt, temp);
            }
        }
    }

    return cnt;
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    for(int i = 1; i <= T; i++){
        cout<<"Case "<<i<<": "<<solve()<<endl;
    }

    return 0;
}
