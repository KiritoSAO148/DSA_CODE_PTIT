#include <bits/stdc++.h>
using namespace std;

int dp[10005];

void solve(){
	for (int i=1; i<=10000; i++){
		dp[i]=i;
		for (int j=1; j<=sqrt(i); j++){
			dp[i]=min(dp[i],dp[i-j*j]+1);
		}
	}
}

int main(){
	int t; cin >> t;
	solve();
	while (t--){
		int n; cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
