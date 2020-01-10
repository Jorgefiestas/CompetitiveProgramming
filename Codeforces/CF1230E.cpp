#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;
const long long mod = 1000000007;
int n, par[1000005];
long long x[100005], mem[1000005];
bool vis[1000005];
vector<pll> gchange[1000005];
vector<int> adjList[1000005];

long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

long long dp(int v){
	if(vis[v])
		return mem[v];
	vis[v] = true;

	long long ans = 0;

	gchange[v].push_back(make_pair(x[v], 1));

	for(pll g : gchange[par[v]]){
		long long tg = gcd(g.first, gchange[v].back().first);
		if(tg == gchange[v].back().first){
			gchange[v].back().second += g.second;
		}
		else{
			gchange[v].push_back(make_pair(tg, g.second));
		}
	}

	for(pll g : gchange[v]){
		ans = (ans + g.first * g.second) % mod;
	}

	return mem[v] = ans;
}

long long dfs(int v, int p){
	par[v] = p;

	long long ans = dp(v);

	for(int u : adjList[v]){
		if(u == p)
			continue;
		ans = (ans + dfs(u, v)) % mod;
	}

	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>x[i];

	int a, b;
    for(int i = 0; i < n - 1; i++){
        cin>>a>>b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
    }

	cout<<dfs(1, 0)<<endl;

    return 0;
}
