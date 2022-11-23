#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
int color[1001];
int in[1001];

bool dfs (int u){
	color[u]=1;
	for (int v : adj[u]){
		if (color[v]==0){
			if (dfs(v)) return true;
		}
		else if (color[v]==1) return true;
	}
	color[u]=2;
	return false;
}

bool kahn(){
	queue<int>q;
	for (int i=1; i<=n; i++){
		if (in[i]==0) q.push(i);
	}
	int cnt=0;
	while (!q.empty()){
		int v=q.front(); q.pop();
		++cnt;
		for (int x : adj[v]){
			--in[x];
			if (in[x]==0) q.push(x);
		}
	}
	if (cnt==n) return false;
	return true;
}

int main(){
	int t; cin >> t;
	while (t--){
		for (int i=0; i<1001; i++) adj[i].clear();
		memset(color,0,sizeof(color));
		cin >> n >> m;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].push_back(y);
			//++in[y];
		}
		//kahn();
		bool ok=false;
		for (int i=1; i<=n; i++){
			if (color[i]==0 && dfs(i)){
				ok=true;
				break;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
