#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int solve(int n, int k){
	int dp[100005]={0};
	dp[0]=1; dp[1]=1;
	for (int i=2; i<=n; i++){
		for (int j=1; j<=min(i,k); j++){
			dp[i]=(dp[i]+dp[i-j])%MOD;
		}
	}
	return dp[n];
}

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		cout << solve(n,k) << endl;
	}
	return 0;
}
