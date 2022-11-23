#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int dp[101][101]={0};
		for (int i=0; i<s.size(); i++){
			dp[i][i]=1;
		}
		for (int i=s.size()-2; i>=0; i--){
			for (int j=i+1; j<s.size(); j++){
				if (s[i]==s[j]) dp[i][j]=dp[i][j]+dp[i+1][j-1]+2;
				else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
		cout << s.size()-dp[0][s.size()-1];
		cout << "\n";
	}
	return 0;
}
