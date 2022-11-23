#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a[1001], dp[1001], ans=0;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++){
		dp[i]=1;
		for (int j=0; j<i; j++){
			if (a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}
