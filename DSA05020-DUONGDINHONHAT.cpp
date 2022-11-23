#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005], a[1005][1005];

int main(){
	int t; cin >> t;
	while (t--){
		int n,m; cin >> n >> m;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++) cin >> a[i][j];
		}
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; i++) dp[i][1]=dp[i-1][1] + a[i][1];
		for (int i=1; i<=m; i++) dp[1][i]=dp[1][i-1] + a[1][i];
		for (int i=2; i<=n; i++){
			for (int j=2; j<=m; j++){
				dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+a[i][j];
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
