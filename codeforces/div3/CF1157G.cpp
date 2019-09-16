#include <bits/stdc++.h>
using namespace std;
int n, m, mat[200][200], r[200], c[200];

void inv_row(int x){
    for(int i = 0; i < m; i++)
        mat[x][i] = !mat[x][i];
}

void inv_col(int x){
    for(int i = 0; i < n; i++)
        mat[i][x] = !mat[i][x];
}

bool check0(int x){
    for(int i = 0; i < m; i++){
        if(mat[x][i] != 0) return false;
    }
    return true;
}

bool check01(int x){
    int i = 0;
    for(; i < m; i++){
        if(mat[x][i] != 0) break;
    }
    for(; i < m; i++){
        if(mat[x][i] == 0) return false;
    }
    return true;
}

bool check1(int x){
    for(int i = 0; i < m; i++){
        if(mat[x][i] != 1) return false;
    }
    return true;
}

void print(int *arr, int s){
    for(int i = 0; i < s; i++)
        cout<<arr[i];
    cout<<endl;
}

bool check(){
    int state = 0;
    for(int i = 0; i < n; i++){
        if(state == 0){
            if(mat[i][0]){
                inv_row(i);
                r[i] = !r[i];
                i--;
                continue;
            }
            if(!check0(i))
                state++;
        }
        if(state == 1){
            if(mat[i][0]){
                inv_row(i);
                r[i] = !r[i];
            }
            if(check01(i)){
                state++;
                continue;
            }
            else{
                return false;
            }
        }
        if(state == 2){
            if(!mat[i][0]){
                inv_row(i);
                r[i] = !r[i];
            }
            if(!check1(i))
                return false;
        }
    }

    return true;
}

int main(){
    cin>>n>>m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>mat[i][j];

    for(int i = 0; i < m; i++){
        if(mat[0][i]){
            inv_col(i);
            c[i] = !c[i];
        }
    }

    if(check()){
        cout<<"YES"<<endl;
        print(r, n);
        print(c, m);
        return 0;
    }

    for(int i = 0; i < m; i++){
        if(!mat[n-1][i]){
            inv_col(i);
            c[i] = !c[i];
        }
    }

    if(check()){
        cout<<"YES"<<endl;
        print(r, n);
        print(c, m);
        return 0;
    }

    cout<<"NO"<<endl;
    return 0;
}
