#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

void nhap(){
	memset(visited,false,sizeof(visited));
	for (int i=0; i<=n; i++) adj[i].clear();
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs (int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]) dfs(v);
	}
}

void canhcau (){
	for (int i=1; i<=n; i++){
		for (int u=0; u<adj[i].size(); u++){
			int j=adj[i][u];
			adj[i].erase(adj[i].begin()+u);
			dfs(i);
			bool check=false;
			for (int k=1; k<=n; k++) if (!visited[k]) check=true;
			if (check && i<j) cout << i << " " << j << " ";
			adj[i].insert(adj[i].begin()+u,j);
			memset(visited,false,sizeof(visited));
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		nhap();
		canhcau();
		cout << "\n";
	}
	return 0;
}
