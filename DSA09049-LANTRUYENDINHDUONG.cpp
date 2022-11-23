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
vi adj[2000001];
bool visited[2000001];
int cnt[2000001];

void inp(){
	ms(visited,false);
	for (int i=1; i<=n; i++) adj[i].clear();
	cin >> n;
	for (int i=1; i<=n-1; i++){
		int x; cin >> x;
		adj[x].pb(i+1);
		adj[i+1].pb(x);
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=adj[i].size(); j++) cout << adj[i][j] << " ";
		cout << endl;
	}
	for (int i=1; i<=n; i++) cnt[i]=1;
}

int dfs (int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]){
			cnt[u]+=cnt[v];
			dfs(v);
		}
	}
	return cnt[u];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	inp();
	for (int i=1; i<=n; i++) cout << cnt[i] << " ";
	return 0;
}

