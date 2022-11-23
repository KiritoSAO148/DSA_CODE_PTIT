#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

void dfs(int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]) dfs(v);
	}
}

void solve(){
	memset(visited,false,sizeof(visited));
	int cnt=0;
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			++cnt;
			dfs(i);
		}
	}
	cout << cnt << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i=0; i<1001; i++) adj[i].clear();
		cin >> n >> m;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		solve();
	}
	return 0;
}
