#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		int ans=0;
		int dp[1005];
		memset(dp,0,sizeof(dp));
		for (int i=0; i<n; i++){
			dp[i]=1;
			for (int j=0; j<i; j++){
				if (a[j]<=a[i]) dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
		cout << n-ans << endl;
	}
	return 0;
}
