#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int tinh(string s1, string s2){
	int m=s1.size(), n=s2.size();
	memset(dp,0,sizeof(dp));
	for (int i=1; i<=m; i++){
		for (int j=1; j<=n; j++){
			if (s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main(){
	int t; cin >> t;
	while (t--){
		string s1, s2; cin >> s1 >> s2;
		cout << tinh(s1,s2) << endl;
	}
	return 0;
}
