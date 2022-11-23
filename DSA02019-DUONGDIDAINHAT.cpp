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

int n,m,ans;
vi adj[25];
bool visited[25][25];

void inp(){
	ans=0;
	cin >> n >> m;
	for (int i=0; i<n; i++) adj[i].clear();
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

void dfs (int u, int cnt){
	for (int v : adj[u]){
		if (!visited[u][v] && !visited[v][u]){
			visited[u][v]=visited[v][u]=true;
			dfs(v,cnt+1);
			visited[u][v]=visited[v][u]=false;
		}
	}
	ans=max(ans,cnt);
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
		inp();
		for (int i=0; i<n; i++){
			ms(visited,false);
			dfs(i,0);
		}
		cout << ans << "\n";
	}
	return 0;
}