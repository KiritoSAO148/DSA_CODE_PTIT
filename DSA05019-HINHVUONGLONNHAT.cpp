#include <bits/stdc++.h>
using namespace std;

int n, m, dp[501][501], a[501][501];

int tinh(){
	memset(dp,0,sizeof(dp));
	for (int i=1; i<=n; i++) dp[i][0]=a[i][0];
	for (int i=1; i<=m; i++) dp[0][i]=a[0][i];
	int ans=0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (a[i][j]){
				dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
			}
			else dp[i][j]=0;
			ans=max(ans,dp[i][j]);
		}
	}
	return ans;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++) cin >> a[i][j];
		}
		cout << tinh() << endl;
	}
	return 0;
}
