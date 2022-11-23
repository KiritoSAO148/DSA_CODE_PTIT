#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int n=s.size();
		int ans=1;
		memset(dp,0,sizeof(dp));
		for (int i=0; i<n; i++) dp[i][i]=1;
		for (int k=1; k<n; k++){
			for (int i=0; i<n-k; i++){
				int j=i+k;
				if (k==1 && s[i]==s[j]) dp[i][j]=1;
				else if (s[i]==s[j] && k>1) dp[i][j]=dp[i+1][j-1];
				else dp[i][j]=0;
				if (dp[i][j]) ans=max(ans,j-i+1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
