#include <bits/stdc++.h>
using namespace std;
long long x, cnt;
unordered_map<int, bool> mem;

int main(){
    cin>>x;
    while(mem.find(x) == mem.end()){
        mem[x] = true;
        x++;
        cnt++;
        while(x%10 == 0) x/=10;
    }
    cout<<cnt<<endl;
    return 0;
}
