#include <bits/stdc++.h>
using namespace std;
vector<int> m, s, p;
map<int, int> mm, mp, ms;

int stair(vector<int> arr){
    if(arr.size() == 0) return 3;
    if(arr.size() == 1) return 2;
    if(arr.size() == 2){
        if(arr[0] + 1 == arr[1]) return 1;
        if(arr[0] + 2 == arr[1]) return 1;
    }
    if(arr[0] + 1 == arr[1]){
        if(arr[1] + 1 == arr[2]){
            return 0;
        }
        return 1;
    }
    if(arr[0] + 2 == arr[1]) return 1;
    if(arr[1] + 1 == arr[2]) return 1;
    if(arr[1] + 2 == arr[2]) return 1;
    return 2;
}

int same(map<int, int> mapa){
    int ans = 0;
    for(auto it : mapa){
        ans = max(ans, it.second);
    }
    return 3 - ans;
}

int main(){
    int t;
    char c;
    for(int i = 0; i<3; i++){
        cin>>t>>c;
        switch(c){
            case 'm':
                m.push_back(t);
                mm[t]++;
                break;
            case 's':
                s.push_back(t);
                ms[t]++;
                break;
            case 'p':
                p.push_back(t);
                mp[t]++;
                break;
        }
    }

    sort(m.begin(), m.end());
    sort(p.begin(), p.end());
    sort(s.begin(), s.end());

    int sol = 5;
    sol = min(sol, stair(m));
    sol = min(sol, stair(s));
    sol = min(sol, stair(p));
    sol = min(sol, same(mm));
    sol = min(sol, same(ms));
    sol = min(sol, same(mp));
        
    cout<<sol<<endl;
}
