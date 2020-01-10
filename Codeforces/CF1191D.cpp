#include <bits/stdc++.h>
using namespace std;
long long n, t, s;
bool flag;
unordered_map<int, int> cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>t;
        s += t;
        cnt[t]++;
    }

    if(cnt.find(0) != cnt.end() && cnt[0] > 1){
        cout<<"cslnb"<<endl;
        return 0;
    }

    for(auto it : cnt){
        if(it.second > 2){
            cout<<"cslnb"<<endl;
            return 0;
        }
        if(it.second == 2 && flag){
            cout<<"cslnb"<<endl;
            return 0;
        }
        if(it.second == 2){
            if(cnt.find(it.first - 1) != cnt.end()){
                cout<<"cslnb"<<endl;
                return 0;
            }
            flag = true;
        }
    }

    s = s - n*(n-1)/2;
    if(s%2)
        cout<<"sjfnb"<<endl;
    else
        cout<<"cslnb"<<endl;

    return 0;
}
