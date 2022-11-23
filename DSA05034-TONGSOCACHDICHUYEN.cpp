#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int dp[1000001];

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		memset(dp,0,sizeof(dp));
		dp[0]=1; dp[1]=1;
		for (int i=2; i<=n; i++){
			for (int j=1; j<=min(i,k); j++){
				dp[i]=(dp[i]+dp[i-j])%MOD;
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}
