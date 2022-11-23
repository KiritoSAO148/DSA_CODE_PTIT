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
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int n,m;
vi adj[1001];
bool visited[1001];

void dfs (int u){
	visited[u]=true;
	for (int v : adj[u]){
		if (!visited[v]) dfs(v);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		ms(visited,false);
		for (int i=1; i<=n; i++) adj[i].clear();
		cin >> n >> m;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		int cnt=0;
		for (int i=1; i<=n; i++){
			if (!visited[i]){
				++cnt;
				dfs(i);
			}
		}
		for (int i=1; i<=n; i++){
			ms(visited,false);
			visited[i]=true;
			int res=0;
			for (int j=1; j<=n; j++){
				if (i!=j){
					if (!visited[j]){
						++res;
						dfs(j);
					}
				}
			}
			if (res>cnt) cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}

