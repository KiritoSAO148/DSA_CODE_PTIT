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

int n,m,M;
vi adj[1001];
int color[1001];
bool visited[1001];

void inp(){
	for (int i=1; i<=n; i++){
		adj[i].clear();
		visited[i]=false;
		color[i]=1;
	}
	cin >> n >> m >> M;
	for (int i=0; i<m; i++){
		int x,y; cin >> x >> y;
		adj[x-1].pb(y-1);
		adj[y-1].pb(x-1);
	}
}

bool bfs(){
	int max_color=1;
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			visited[i]=true;
			queue<int>q;
			q.push(i);
			while (sz(q)){
				int v=q.front(); q.pop();
				for (int x : adj[v]){
					if (color[x]==color[v]) color[x]++;
					max_color=max(max_color,max(color[x],color[v]));
					if (max_color>M) return false;
					if (!visited[x]){
						visited[x]=true;
						q.push(x);
					}
				}
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		inp();
		if (bfs()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

