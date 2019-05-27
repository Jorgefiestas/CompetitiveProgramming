#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int, unordered_map<int, unordered_map<int, double>>> mem;
pair<int, double> trip[10000];
double dis[] = {1, 0.5, 0.25, 0.25, 0.25, 0.25};

double minCost(int i, int t, int s){
	if(i == n-1) return dis[s]*trip[i].second;
	if(mem[i][t][s]) return mem[i][t][s];
	double cost = DBL_MAX;
	if(t + trip[i].first < 120 && s<5) cost = minCost(i+1, t + trip[i].first, s+1);
	cost = min(cost, minCost(i+1, 0, 0));
	cost += dis[s]*trip[i].second;
	mem[i][t][s] = cost;
	return cost;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>trip[i].first>>trip[i].second;
	}
	printf("%.2F\n", minCost(0, 0, 0));
	return 0;
}
