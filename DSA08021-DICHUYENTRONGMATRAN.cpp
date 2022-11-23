#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1001][1001];
bool visited[1001][1001];
int d[1001][1001];

typedef pair<int,int> pi;
#define fi first
#define se second

int bfs(int i, int j){
	queue<pi>q;
	q.push({i,j});
	visited[i][j]=true;
	d[i][j]=0;
	while (!q.empty()){
		pi top = q.front(); q.pop();
		int i = top.fi, j = top.se;
		if (i==m && j==n) return d[i][j];
		if (i+a[i][j]<=m && !visited[i+a[i][j]][j]){
			visited[i+a[i][j]][j]=true;
			d[i+a[i][j]][j]=d[i][j]+1;
			q.push({i+a[i][j],j});
		}
		if (j+a[i][j]<=n && !visited[i][j+a[i][j]]){
			visited[i][j+a[i][j]]=true;
			d[i][j+a[i][j]]=d[i][j]+1;
			q.push({i,j+a[i][j]});
		}
	}
	return -1;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> m >> n;
		memset(d,0,sizeof(d));
		memset(visited,false,sizeof(visited));
		for (int i=1; i<=m; i++){
			for (int j=1; j<=n; j++) cin >> a[i][j];
		}
		cout << bfs(1,1) << endl;
	}
	return 0;
}
