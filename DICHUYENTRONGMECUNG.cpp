#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

vector<string>v;
string s="DLRU";
int n, a[100][100], ok;

void Try(int i, int j, string res){
	if (i==n && j==n){
		v.push_back(res);
		ok=1; return;
	}
	for (int k=0; k<4; k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if (i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]==1){
			a[i1][j1]=0;
			Try(i1,j1,res+s[k]);
			a[i1][j1]=1;
		}
	}
}

void inp(){
	cin >> n;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cin >> a[i][j];
	}
	v.clear();
	ok=0;
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
		if (a[1][1] && a[n][n]){
			a[1][1]=0;
			Try(1,1,"");
		}
		if (!ok) cout << "-1\n";
		else{
			cout << v.size() << " ";
			for (auto it : v) cout << it << " ";
			cout << endl;
		}
	}
	return 0;
}
