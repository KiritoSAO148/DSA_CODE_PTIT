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

int n,m;
int d[501][501];
int a[501][501];

int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};

bool check(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (a[i][j]!=2) return false;
		}
	}
	return true;
}

int bfs (int i, int j){
	queue<pi>q;
	q.push({i,j});
	d[i][j]=0;
	while (!q.empty()){
		pi top=q.front(); q.pop();
		int i=top.fi, j=top.se;
		if (check()) return d[i][j];
		for (int k=0; k<4; k++){
			int i1=i+dx[k];
			int j1=j+dy[k];
			if (i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]<2){
				d[i1][j1]=d[i][j]+1;
				a[i1][j1]++;
				q.push({i1,j1});
			}
		}
	}
	return -1;
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
		cin >> n >> m;
		ms(d,0);
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++) cin >> a[i][j];
		}
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				if (a[i][j]<2) cout << bfs(i,j);
			}
		}
		cout << "\n";
	}
	return 0;
}