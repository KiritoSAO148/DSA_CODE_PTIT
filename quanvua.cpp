#include <bits/stdc++.h>
using namespace std;

#define n 8

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int s, t, u, v;
int d[1001][1001];
int a[1001][1001];

void ktao(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) a[i][j]=1;
	}
}

void bfs (int i, int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	d[i][j]=0;
	while (!q.empty()){
		pair<int,int>top=q.front(); q.pop();
		int x=top.first, y=top.second;
		if (x==u && y==v) return;
		for (int k=0; k<n; k++){
			int x1=x+dx[k];
			int y1=y+dy[k];
			if (x1>=1 && x1<=n && y1>=1 && y1<=n && a[x1][y1]==1){
				a[x1][y1]=0;
				d[x1][y1]=d[x][y]+1;
				q.push({x1,y1});
			}
		}
	}
}

int main(){
	cin >> s >> t >> u >> v;
	ktao();
	bfs(s,t);
	cout << d[u][v];
	return 0;
}
