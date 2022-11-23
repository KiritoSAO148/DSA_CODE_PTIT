#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1001];
int n,m;

int solve(int n){
	int cnt=0;
	for (int i=1; i<=n; i++){
		if (adj[i].size()%2) ++cnt;
	}
	if (cnt==0) return 2;
	if (cnt==2) return 1;
	return 0;
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i=1; i<=n; i++) adj[i].clear();
		cin >> n >> m;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		cout << solve(n) << endl;
	}
	return 0;
}
