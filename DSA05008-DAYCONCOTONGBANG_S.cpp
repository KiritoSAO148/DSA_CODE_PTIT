#include <bits/stdc++.h>
using namespace std;

int a[201], dp[40001], n, s;

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		for (int i=0; i<n; i++) cin >> a[i];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for (int i=0; i<n; i++){
			for (int j=s; j>=a[i]; j--){
				if (dp[j]==0 && dp[j-a[i]]==1) dp[j]=1;
			}
		}
		if (dp[s]==1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
