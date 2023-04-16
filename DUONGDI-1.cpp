#include <bits/stdc++.h>
using namespace std;

int n,m,st,en;
vi adj[1001];
bool visited[1001];
int par[1001];
vi path;

void inp(){
	cin >> n >> m >> st >> en;
	for (int i=1; i<=n; i++) adj[i].clear();
	memset(visited, false, sizeof(visited));
	memset(par, 0, sizeof(par));
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
	}
	path.clear();
}

void bfs(int u){
	queue<int>q;
	q.push(u);
	visited[u]=true;
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				par[x]=v;
				visited[x]=true;
				q.push(x);
			}
		}
	}
}

void find (int st, int en){
	bfs(st);
	if (!visited[en]){
		cout << "-1\n"; return;
	}
	while (st!=en){
		path.push_back(en);
		en=par[en];
	}
	path.puss_back(st);
	reverse(begin(path), end(path));
	for (int x : path) cout << x << " ";
	cout << "\n";
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
		find(st,en);
	}
	return 0;
}
