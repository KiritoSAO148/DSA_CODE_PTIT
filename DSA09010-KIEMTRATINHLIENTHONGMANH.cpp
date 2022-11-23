#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1001],r_adj[1001];
bool visited[1001];
stack <int> st;

void inp(){
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}

void dfs1(int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]) dfs1(v);
	}
	st.push(u);
}

void dfs2(int u){
	visited[u]=true;
	for (int v : r_adj[u]){
		if (!visited[v]) dfs2(v);
	}
}

void SCC(){
	memset(visited,false,sizeof(visited));
	for (int i=1; i<=n; i++){
		if (!visited[i]) dfs1(i);
	}
	memset(visited,false,sizeof(visited));
	int cnt=0;
	while (!st.empty()){
		int u=st.top(); st.pop();
		if (!visited[u]){
			dfs2(u);
			++cnt;
		}
	}
	if (cnt==1) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		for (int i=1; i<=n; i++){
			adj[i].clear();
			r_adj[i].clear();
		}
		inp();
		SCC();
	}
	return 0;
}
