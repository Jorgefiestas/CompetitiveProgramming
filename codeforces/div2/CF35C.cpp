#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y;
bool trees[2005][2005];
queue<pair<int, int>> q;

bool check(int i, int j){
    if(i<0 || j< 0 || i>=n || j>=m) return true;;
    if(!trees[i][j]){
        trees[i][j] = true;
        return false;
    }
    return true;
}

void bfs(){
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(!check(x + 1, y)) q.push(make_pair(x + 1, y));
        if(!check(x - 1, y)) q.push(make_pair(x - 1, y));
        if(!check(x, y + 1)) q.push(make_pair(x, y + 1));
        if(!check(x, y - 1)) q.push(make_pair(x, y - 1));
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>n>>m>>k;
    int tx, ty;
    for(int i = 0; i<k; i++){
        in>>tx>>ty;
        tx--, ty--;
        q.push(make_pair(tx, ty));
        trees[tx][ty] = true;
    }
    bfs();
    out<<x+1<<" "<<y+1<<endl;
    return 0;
}
