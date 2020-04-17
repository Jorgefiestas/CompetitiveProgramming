#include <bits/stdc++.h>
using namespace std;
deque<int> pos[3];
string str, ans;
int flag;

int main(){
    cin>>str;

    for(int i = 0; i < str.size(); i++){
        pos[str[i] - 'a'].push_back(i);
    }

    while(!pos[0].empty() || !pos[1].empty() || !pos[2].empty()){
        int s = - 1;
        int t = -1;

        for(int i = 0; i < 3; i++){
            if(pos[i].empty()) continue;
            if(pos[i].back() - pos[i].front() > s){
                s = pos[i].back() - pos[i].front();
                t = i;
            }
        }

        for(int i = 0; i < 3; i++){
            while(!pos[i].empty() && pos[i].front() < pos[t].front())
                pos[i].pop_front();

            while(!pos[i].empty() && pos[i].back() > pos[t].back())
                pos[i].pop_back();
        }

        pos[t].pop_back();
        if(!pos[t].empty())
            pos[t].pop_front();

        ans += 'a' + t;
        if(s == 0) flag = 1;
    }

    if(2*ans.size() - flag >= str.size()/2){
        cout<<ans;
        for(int i = ans.size() - 1 - flag; i >= 0; i--)
            cout<<ans[i];
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
