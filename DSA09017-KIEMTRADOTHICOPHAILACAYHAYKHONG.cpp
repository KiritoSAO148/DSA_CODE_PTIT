#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> adj[1001];
bool visited[1001];

bool dfs (int u, int par){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]){
			if (dfs(v,u)) return true;
		}
		else if (v != par) return true;
	}
	return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i=0; i<1001; i++) adj[i].clear();
		memset(visited,false,sizeof(visited));
		for (int i=0; i<n-1; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bool ok=true;
		if (dfs(1,0)){
			cout << "NO\n";
		}else{
			for (int i=1; i<=n; i++){
				if (!visited[i]){
					ok=false; break;
				}
			}
			if (ok) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
