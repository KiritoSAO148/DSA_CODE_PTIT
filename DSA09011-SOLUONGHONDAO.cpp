#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1001][1001];
bool visited[1001][1001];
int cnt;

int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};

void dfs(int i, int j){
	visited[i][j]=true;
	for (int k=0; k<8; k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if (i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]==1 && !visited[i1][j1]){
			dfs(i1,j1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++) cin >> a[i][j];
		}
		cnt=0;
		memset(visited,false,sizeof(visited));
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				if (a[i][j]==1 && !visited[i][j]){
					dfs(i,j);
					++cnt;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
