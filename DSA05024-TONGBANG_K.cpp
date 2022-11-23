#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int dp[1001], a[1001], n, k;

int tinh(){
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for (int i=1; i<=k; i++){
		for (int j=1; j<=n; j++){
			if (a[j]<=i) dp[i]=(dp[i]+dp[i-a[j]])%MOD;
		}
	}
	return dp[k];
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i=1; i<=n; i++) cin >> a[i];
		cout << tinh() << endl;
	}
	return 0;
}
