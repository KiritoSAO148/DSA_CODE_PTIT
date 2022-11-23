#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> pd;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int dp[501];
		memset(dp,0,sizeof(dp));
		int ans=0;
		pd p[n];
		for (int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
		for (int i=0; i<n; i++){
			dp[i]=1;
			for (int j=0; j<i; j++){
				if (p[i].first>p[j].first && p[i].second<p[j].second){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
