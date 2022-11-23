#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101];

int tinh(string s1, string s2, string s3){
	int m=s1.size(), n=s2.size(), p=s3.size();
	memset(dp,0,sizeof(dp));
	for (int i=1; i<=m; i++){
		for (int j=1; j<=n; j++){
			for (int k=1; k<=p; k++){
				if (s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
					dp[i][j][k]=dp[i-1][j-1][k-1]+1;
				else
					dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
			}
		}
	}
	return dp[m][n][p];
}

int main(){
	int t; cin >> t;
	while (t--){
		int m,n,p; cin >> m >> n >> p;
		string s1, s2, s3; cin >> s1 >> s2 >> s3;
		cout << tinh(s1,s2,s3) << endl;
	}
	return 0;
}
