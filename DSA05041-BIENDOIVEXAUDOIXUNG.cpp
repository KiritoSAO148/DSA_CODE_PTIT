#include <bits/stdc++.h>
using namespace std;

int tinh(string s, int n){
	int dp[101][101]={0};
	for (int i=0; i<n; i++) dp[i][i]=1;
	for (int i=n-1; i>=0; i--){
		for (int j=i+1; j<n; j++){
			if (s[i]==s[j]) dp[i][j]+=dp[i+1][j-1]+2;
			else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
		}
	}
	return n-dp[0][n-1];
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		cout << tinh(s,s.size()) << endl;
	}
	return 0;
}
