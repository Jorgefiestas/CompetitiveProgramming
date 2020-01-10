#include <bits/stdc++.h>
using namespace std;
int n, k, mx[2] = {-1, -1}, mn[2] = {INT_MAX, INT_MAX};
bool flag;
string str;

int main(){
    cin>>n>>k>>str;

    for(int i = 0; i < n; i++){
        if(str[i] == '0')
            mn[0] = min(mn[0], i);
        else
            mn[1] = min(mn[1], i);

        if(mn[0] != INT_MAX && mn[1] != INT_MAX)
            break;
    }

    for(int i = n - 1; i >= 0; i--){
        if(str[i] == '0')
            mx[0] = max(mx[0], i);
        else
            mx[1] = max(mx[1], i);

        if(mx[0] >= 0 && mx[1] >= 0)
            break;
    }

    if(mx[0] - mn[0] + 1 <= k || mx[1] - mn[1] + 1 <= k){
        cout<<"tokitsukaze"<<endl;
        return 0;
    }

    if(mn[0] >= k || mn[1] >= k)
        flag = true;
    if(n - mx[0] - 1 >= k || n - mx[1] - 1 >= k)
        flag = true;
    if(mx[0] - mn[0] - 1 >= k || mx[1] - mn[1] - 1 >= k)
        flag = true;

    if(flag)
        cout<<"once again"<<endl;
    else
        cout<<"quailty"<<endl;

    return 0;
}
