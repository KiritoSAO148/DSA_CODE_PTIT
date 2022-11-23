#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1001];
bool visited[1001];
int n,m;
int ok;

void dfs (int u, int cnt){
	if (cnt==n) ok = true;
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]) dfs(v,cnt+1);
	}
	visited[u]=false;
}

int solve(){
	for (int i=1; i<=n; i++){
		ok=false;
		dfs(i,1);
		if (ok) return 1;
	}
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
		cout << solve() << endl;
	}
	return 0;
}
