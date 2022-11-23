#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

void bfs(int u){
	queue <int> q;
	q.push(u);
	visited[u]=true;
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x]=true;
			}
		}
	}
}

void solve(){
	memset(visited,false,sizeof(visited));
	int cnt=0;
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			++cnt;
			bfs(i);
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
