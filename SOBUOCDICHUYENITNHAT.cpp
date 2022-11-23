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

int a[1001][1001];
int n,m;
int d[1001][1001];
bool visited[1001][1001];

int solve (){
	queue<pi>q;
	q.push({1,1});
	d[1][1]=0;
	visited[1][1]=true;
	while (!q.empty()){
		pi top=q.front(); q.pop();
		int i=top.fi, j=top.se;
		if (i==n && j==m) return d[i][j];
		int x=abs(a[i+1][j]-a[i][j]);
		int y=abs(a[i][j+1]-a[i][j]);
		int z=abs(a[i+1][j+1]-a[i][j]);
		if (i+x<=n && !visited[i+x][j]){
			visited[i+x][j]=true;
			q.push({i+x,j});
			d[i+x][j]=d[i][j]+1;
		}
		if (j+y<=m && !visited[i][j+y]){
			visited[i][j+y]=true;
			q.push({i,j+y});
			d[i][j+y]=d[i][j]+1;
		}
		if (i+z<=n && j+z<=m && !visited[i+z][j+z]){
			visited[i+z][j+z]=true;
			q.push({i+z,j+z});
			d[i+z][j+z]=d[i][j]+1;
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
		ms(d,0);
		cin >> n >> m;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++) cin >> a[i][j];
		}
		cout << solve() << "\n";
	}
	return 0;
}