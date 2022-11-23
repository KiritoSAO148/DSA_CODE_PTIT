#include <bits/stdc++.h>
using namespace std;

int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

typedef pair<int,int> pi;

int si,sj,ti,tj;

int d[10][10];
bool visited[10][10];

int bfs (int i, int j){
	queue<pi>q;
	q.push({i,j});
	visited[i][j]=true;
	d[i][j]=0;
	while (!q.empty()){
		pi top = q.front(); q.pop();
		int i=top.first, j=top.second;
		if (i==ti && j==tj) return d[i][j];
		for (int k=0; k<8; k++){
			int i1=i+dx[k];
			int j1=j+dy[k];
			if (i1>=1 && i1<=8 && j1>=1 && j1<=8 && !visited[i1][j1]){
				d[i1][j1]=d[i][j]+1;
				visited[i1][j1]=true;
				q.push({i1,j1});
			}
		}
	}
}

void inp(){
	string s; cin >> s;
	si=s[1]-'0';
	sj=(s[0]-'a')+1;
	string t; cin >> t;
	ti=t[1]-'0';
	tj=(t[0]-'a')+1;
	memset(visited,false,sizeof(visited));
	memset(d,0,sizeof(d));
	cout << bfs(si,sj) << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
	}
	return 0;
}
