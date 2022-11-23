#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
vector<int>adj[1001];
int n,m,u;
bool visited[1001];
vector<pi>ans;

void dfs(int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]){
			ans.push_back({u,v});
			dfs(v);
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		memset(visited,false,sizeof(visited));
		for (int i=1; i<=n; i++) adj[i].clear();
		ans.clear();
		cin >> n >> m >> u;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(u);
		if (ans.size()!=n-1) cout << -1 << endl;
		else{
			for (auto it : ans) cout << it.first << " " << it.second << endl;
		}
	}
	return 0;
}
