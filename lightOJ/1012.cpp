#include <bits/stdc++.h>
using namespace std;
int T, h, w;
vector<int> ds;
vector<int> size(ds);
vector<string> land;

int findRoot(int i){
    while(ds[i] != i){
        ds[i] = ds[ds[i]];
        i = ds[i];
    }
    return i;
}

void join(int i, int j){
    int rooti = findRoot(i);
    int rootj = findRoot(j);
    if(rooti == rootj) return;
    ds[rootj] = rooti;
    size[rooti] += size[rootj];
}

int solve(){
    land.clear();
    size.clear();
    ds.clear();

    cin>>w>>h;
    ds.resize(w*h);
    size.resize(w*h);
    land.resize(h);

    for(int i = 0; i < w*h; i++){
        ds[i] = i;
        size[i] = 1;
    }

    for(int i = 0; i < h; i++){
        cin>>land[i];
    }

    int x, y;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(land[i][j] == '#') continue;
            if(land[i][j] == '@'){
                x = i;
                y = j;
            }
            if(i && land[i - 1][j] != '#'){
                join(i*w + j, (i - 1)*w + j);
            }
            if(i != h - 1 && land[i + 1][j] != '#'){
                join(i*w + j, (i + 1)*w + j);
            }
            if(j && land[i][j - 1] != '#'){
                join(i*w + j, i*w + j - 1);
            }
            if(j != w - 1 && land[i][j + 1] != '#'){
                join(i*w + j, i*w + j + 1);
            }
        }
    }

    return size[findRoot(x*w + y)];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    for(int i = 1; i<= T; i++){
        cout<<"Case "<<i<<": "<<solve()<<endl;
    }

    return 0;
}
