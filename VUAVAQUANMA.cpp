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

int dx1[8] = {-2,-2,-1,1,2,2,1,-1};
int dy1[8] = {-1,1,2,2,1,-1,-2,-2};

int dx2[8]={-1,-1,-1,0,0,1,1,1};
int dy2[8]={-1,0,1,1,-1,1,-1,-1};

int n;
char a[101][101];
int d1[101][101], d2[101][101];
bool visited[101][101];

void inp(){
	cin >> n;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cin >> a[i][j];
	}
}

int x,y,u,v;

void ma (int i, int j){
	queue<pi>q;
	q.push({i,j});
	visited[i][j]=true;
	d1[i][j]=0;
	while (!q.empty()){
		pi top=q.front(); q.pop();
		int i=top.fi, j=top.se;
		if (i==n && j==n) return;
		for (int k=0; k<8; k++){
			int i1=i+dx1[k];
			int j1=j+dx1[k];
			if (i1>=1 && i1<=n && j1>=1 && j1<=n && !visited[i1][j1] && a[i1][j1]!='#'){
				visited[i1][j1]=true;
				d1[i1][j1]=d1[i][j]+1;
				q.push({i1,j1});
			}
		}
	}
}

int vua (int i, int j){
	queue<pi>q;
	q.push({i,j});
	visited[i][j]=true;
	d2[i][j]=0;;
	while (!q.empty()){
		pi top=q.front();
		q.pop();
		int i=top.fi, j=top.se;
		if (d2[i][j]==d1[i][j]) return d2[i][j];
		for (int k=0; k<8; k++){
			int i1=i+dx2[k];
			int j1=j+dx2[k];
			if (i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]!='#'){
				visited[i1][j1]=true;
				d2[i1][j1]=d2[i][j]+1;
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
	inp();
	int x,y,u,v;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (a[i][j]=='M'){
				x=i; y=j;
			}
			if (a[i][j]=='T'){
				u=i; v=j;
			}
		}
	}
	//cout << x << y << u << v << "\n";
	ma(x,y);
	cout << "\n";
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cout << d1[i][j] << " ";
		cout << "\n";
	}
	ms(visited,false);
	cout << "\n";
	cout << vua(u,v) << "\n";
	cout << "\n";
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cout << d2[i][j] << " ";
		cout << "\n";
	}
	return 0;
}