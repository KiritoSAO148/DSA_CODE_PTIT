#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		pair<int,int>p[n];
		int dp[101]={0};
		for (int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
		sort(p,p+n,cmp);
		int ans=0;
		for (int i=0; i<n; i++){
			dp[i]=1;
			for (int j=0; j<i; j++){
				if (p[j].second<p[i].first) dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
