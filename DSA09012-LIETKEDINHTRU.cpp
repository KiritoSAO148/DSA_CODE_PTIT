#include <bits/stdc++.h>
using namespace std;

int n,m,timer;
int disc[1001], low[1001];
vector <int> adj[1001];
bool dinhtru[1001];

void nhap(){
	cin >> n >> m;
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(disc,0,sizeof(disc));
	memset(low,0,sizeof(low));
	memset(dinhtru,false,sizeof(dinhtru));
}

void dfs (int u, int par){
	disc[u]=low[u]=++timer;
	int child=0;
	for (int v : adj[u]){
		if (v==par) continue;
		if (!disc[v]){
			++child;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if (par!=-1 && low[v]>=disc[u])
				dinhtru[u]=true;
		}else low[u]=min(low[u],disc[v]);
	}
	if (par==-1 && child>1) dinhtru[u]=true;
}

int main(){
	int t; cin >> t;
	while (t--){
		nhap();
		for (int i=1; i<=n; i++){
			if (!disc[i])
				dfs(i,-1);
		}
		for (int i=1; i<=n; i++){
			if (dinhtru[i]) cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
