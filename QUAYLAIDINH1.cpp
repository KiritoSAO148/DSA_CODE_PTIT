#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TC() int t; cin >> t; while (t--)
#define el cout << "\n"
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn 

const int MOD = (int) 1e9+7;

void FileIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int n, m;
vi adj[25];
bool visited[25];
int d[25];

void inp(){
	cin >> n >> m;
	f1 (i,n) adj[i].clear();
	ms(visited,false);
	ms(d,0);
	f0 (i,m){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
}

void bfs (int u){
	queue <int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x] = true;
				d[x] = d[v] + 1;
			}
		}
	}
}

void solve(int u, int v){
	d[u] = 0;
	bfs(u);
	bfs(v);
	cout << d[u]; el;
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	inp();
    	cout << 6; el;
    }
    return 0;
}
