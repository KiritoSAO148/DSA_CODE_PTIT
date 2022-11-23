#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int n,m,u,v,cnt;
vi adj[1001];
bool visited[1001], check[1001];

void inp(){
	cnt=0;
	cin >> n >> m >> u >> v;
	for (int i=1; i<=n; i++){
		adj[i].clear();
		visited[i]=false;
		check[i]=true;
	}
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
	}
}

void dfs (int u, int v){
	if (u==v){
		for (int i=1; i<=n; i++){
			if (visited[i] && check[i]){
				check[i]=true;
			}else check[i]=false;
		}
	}else{
		for (int x : adj[u]){
			if (!visited[x]){
				visited[x]=true;
				dfs(x,v);
				visited[x]=false;
			}
		}
	}
}

void solve(){
	visited[u]=true;
	dfs(u,v);
	visited[u]=false;
	for (int i=1; i<=n; i++){
		if (i!=u && i!=v && check[i]) ++cnt;
	}
	cout << cnt << "\n";
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		solve();
	}
	return 0;
}