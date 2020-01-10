#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int q, n, k, cnt[100005], ans[50005];
int last = 2;
vector<vector<int>> Q;

void add(int *bit, int idx) {
    while (idx <= 100005) {
        bit[idx]++;
        idx += idx & (-idx);
    }
}

int sum(int *bit, int idx){
    int s = 0;
    while(idx > 0){
        s += bit[idx];
        idx -= idx & (-idx);
    }
    return s;
}


int largest_prime_factor(int x){
    int lpf = -1;

    while(x % 2 == 0){
        lpf = 2;
        x >>= 1;
    }

    for(int i = 2; i*i <= x; i++){
        while(x % i == 0){
            lpf = i;
            x /= i;
        }
    }

    if(x > 2)
        lpf = x;

    return lpf;
}

void update_k(int m){
    for(int i = last; i <= m; i++){
        int lpf = largest_prime_factor(i);
        add(cnt, lpf);
    }

    last = m + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>q;

    for(int i = 0; i < q; i++){
        cin>>n>>k;
        Q.push_back({n, k, i});
    }

    auto comp = [](vi &a, vi &b){
        return a[0] < b[0];
    };
    sort(Q.begin(), Q.end(), comp);

    for(vi qu : Q){
        update_k(qu[0]);
        ans[qu[2]] = sum(cnt, qu[1]);
    }

    for(int i = 0; i < q; i++)
        cout<<ans[i]<<endl;

    return 0;
}
