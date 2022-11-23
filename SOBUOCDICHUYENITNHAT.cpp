#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1001][1001],c[1001][1001];
bool ok;

void nhap(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
}

int dichuyen(){
	queue<pair<int,int>> q;
	q.push({1,1});
	c[1][1]=0;
	while(!q.empty()){
		pair<int,int> top=q.front();
		q.pop();
		int i=top.first,j=top.second;
		if(i==m && j==n){
		return c[i][j];
	} 
	int x=abs(a[i+1][j]-a[i][j]);
	int y=abs(a[i][j]-a[i][j+1]);
	int z=abs(a[i+1][j+1]-a[i][j]);
	if(i+x<=m && c[i+x][j]==0 ){
		q.push({i+x,j});
		c[i+x][j]=c[i][j] + 1;
	}
	if(j+y<=n && c[i][j+y]==0){
		q.push({i,j+y});
		c[i][j+y]=c[i][j]+1;
	}
	if(j+z<=n && i+z<=m && c[i+z][j+z]==0){
		q.push({i+z,j+z});
		c[i+z][j+z]=c[i][j]+1;
	}
	}
	return -1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(c,0,sizeof(c));
		nhap();
		cout<<dichuyen()<<endl;
	}
}
