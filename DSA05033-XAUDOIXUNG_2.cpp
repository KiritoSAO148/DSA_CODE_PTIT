#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int dp[101][101]={0};
		int n=s.size();
		for (int i=0; i<n; i++) dp[i][i]=1;
		for (int i=n-1; i>=0; i--){
			for (int j=i+1; j<n; j++){
				if (s[i]==s[j]) dp[i][j]+=dp[i+1][j-1]+2;
				else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
		cout << n-dp[0][n-1] << endl;
	}
	return 0;
}
