#include <bits/stdc++.h>
using namespace std;
long long n, m, q, temp, mx, a, b;
deque<long long> dq;
vector<pair<int, int>> mem(1000000);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>temp;
        dq.push_back(temp);
        if(temp > mx)
            mx = temp;
    }

    long long idx = 1;
    while(dq.front() != mx){
        a = dq.front(), dq.pop_front();
        b = dq.front(), dq.pop_front();
        mem[idx++] = make_pair(a, b);

        if(a > b){
            dq.push_front(a);
            dq.push_back(b);
        }
        else{
            dq.push_front(b);
            dq.push_back(a);
        }
    }
    long long offset = idx;
    for(int i = 0; i < n - 1; i++){
        a = dq.front(), dq.pop_front();
        b = dq.front(), dq.pop_front();
        mem[idx++] = make_pair(a, b);

        if(a > b){
            dq.push_front(a);
            dq.push_back(b);
        }
        else{
            dq.push_front(b);
            dq.push_back(a);
        }
    }
    
    for(int i = 0; i < q; i++){
        cin>>m;
        if(m > offset){
            m = (m - offset)%(n-1);
            m = offset + m;
        }
        cout<<mem[m].first<<" "<<mem[m].second<<endl;
    }

    return 0;
}
