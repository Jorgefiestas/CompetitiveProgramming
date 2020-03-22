#include <bits/stdc++.h>
using namespace std;
int n, q;
unordered_map<int, unordered_map<int, int>> mem, val;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>val[i][i];
        mem[i][i] = 0;
    }

    for(int i = 2; i <= n; i += i){
        for(int j = 0; j + i - 1 < n; j++){
            int k = j + i - 1;
            int m = (j + k)/2;
            mem[j][k] = mem[j][m] + mem[m + 1][k];
            if(val[j][m] + val[m + 1][k] >= 10)
                mem[j][k]++;
            val[j][k] = (val[j][m] + val[m + 1][k])%10;
        }
    }

    cin>>q;
    int l, r;
    for(int i = 0; i < q; i++){
        cin>>l>>r;
        l--, r--;
        cout<<mem[l][r]<<endl;
    }

    return 0;
}
