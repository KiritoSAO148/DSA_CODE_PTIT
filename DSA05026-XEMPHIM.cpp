#include <bits/stdc++.h>
using namespace std;

int dp[101][25001];

int main(){
	int C,n; cin >> C >> n;
	memset(dp,0,sizeof(dp));
	int w[n+1];
	for (int i=1; i<=n; i++) cin >> w[i];
	for (int i=1; i<=n; i++){
		for (int j=1; j<=C; j++){
			if (j<w[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j-w[i]]+w[i],dp[i-1][j]);
		}
	}
	cout << dp[n][C] << endl;
	return 0;
}
