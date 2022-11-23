#include <bits/stdc++.h>
using namespace std;

int dp[10001], n;

void sieve(){
	int i=1, j=1, k=1;
	dp[1]=1;
	for (int a=2; a<10000; a++){
		dp[a]=min(dp[i]*2,min(dp[j]*3,dp[k]*5));
		if (dp[a]==dp[i]*2) ++i;
		if (dp[a]==dp[j]*3) ++j;
		if (dp[a]==dp[k]*5) ++k;
	}
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
