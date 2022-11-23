#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, C[20][20], upd[20], x[20], visited[20], ans=1e9, cmin=1e9, cost=0;

void check(int s){
	if (s+C[x[n]][x[1]]<ans){
		int tmp=s+C[x[n]][x[1]];
		ans=min(ans,tmp);
		for (int i=1; i<=n; i++) upd[i]=x[i];
	}
}

void Try(int i){
	for (int j=2; j<=n; j++){
		if (!visited[j]){
			x[i]=j;
			visited[j]=1;
			cost+=C[x[i-1]][x[i]];
			if (i==n){
				check(cost);
			}
			else if (cost+(n-i+1)*cmin<ans) Try(i+1);
			cost-=C[x[i-1]][x[i]];
			visited[j]=0;
		}
	}
}

void inp(){
	cin >> n;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> C[i][j];
			if (i!=j) cmin=min(cmin,C[i][j]);
		}
	}
	x[1]=1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	inp();
	Try(2);
	cout << "(";
	for (int i=1; i<=n; i++) cout << upd[i] << ",";
	cout << upd[1] << ")\n";
	cout << ans << "\n";
	return 0;
}
