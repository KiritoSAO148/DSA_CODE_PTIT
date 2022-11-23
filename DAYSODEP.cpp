#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n+1];
		for (int &x : a) cin >> x;
		int ans=0;
		int dp[100];
		memset(dp,0,sizeof(dp));
		dp[1]=a[1];
		for (int i=2; i<=n; i++){
			dp[i]=1;
			for (int j=1; j<i; j++){
				if (max(a[j],a[i])<=2*min(a[j],a[i])) dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
