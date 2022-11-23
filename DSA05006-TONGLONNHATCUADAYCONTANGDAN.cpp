#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int dp[1001];
		memset(dp,0,sizeof(dp));
		int a[1001];
		for (int i=1; i<=n; i++) cin >> a[i];
		int ans=0;
		for (int i=1; i<=n; i++){
			dp[i]=a[i];
			for (int j=1; j<i; j++){
				if (a[j]<a[i])
					dp[i]=max(dp[i],dp[j]+a[i]);
			}
			ans=max(ans,dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
