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

int n;
vi adj[1001];
bool visited[1001];
int ans;
bool ok;

void inp(){
	cin >> n;
	ms(visited,false);
	for (int i=1; i<=n; i++) adj[i].clear();
	for (int i=0; i<n-1; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

void dfs (int u,  int cnt, int v){
	if (ok) return;
	visited[u]=true;
	if (u==v){
		ans=cnt;
		ok=true;
		return;
	}
	for (int x : adj[u]){
		if (!visited[x]) dfs(x,cnt+1,v);
	}
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
		int q; cin >> q;
		while (q--){
			int u,v; cin >> u >> v;
			ans=0;
			ok=false;
			ms(visited,false);
			dfs(u,0,v);
			cout << ans << "\n";
		}
	}
	return 0;
}