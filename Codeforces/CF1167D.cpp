#include <bits/stdc++.h>
using namespace std;
int n;
bool states[200005];
string str, res;
stack<int> open;

void addRes(bool s){
    if(s) res+='1';
    else res += '0';
}

int main(){
    cin>>n>>str;
    bool state = false;

    for(int i = 0; i<n; i++){
        while(str[i] == ')'){
            state = states[open.top()];
            open.pop();
            addRes(state);
            states[i] = state;
            i++;
            if(i == n) break;
        }
        if(i == n) break;
        open.push(i);
        addRes(state);
        states[i] = state;
        state = !state;
    }
    cout<<res<<endl;
    return 0;
}
