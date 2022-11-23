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

int k,n,m;
vi adj[10001];
bool visited[10001];
vi vitri;
int cnt[10001];

void inp(){
	ms(cnt,0);
	vitri.clear();
	for (int i=1; i<=n; i++) adj[i].clear();
	cin >> k >> n >> m;
	for (int i=0; i<k; i++){
		int x; cin >> x;
		vitri.pb(x);
	}
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x].pb(y);
	}
}

void dfs (int u){
	cnt[u]++;
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]) dfs(v);
	}
}

int solve(){
	for (int i=0; i<sz(vitri); i++){
		ms(visited,false);
		dfs(vitri[i]);
	}
	int ans=0;
	for (int i=1; i<=n; i++){
		if (cnt[i]==k) ++ans;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	inp();
	cout << solve();
	return 0;
}

