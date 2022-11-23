#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9+7;
using ll = long long;

ll tinh(int n){
	ll dp[10][n+1];
	memset(dp,0,sizeof(dp));
	for (int i=0; i<=9; i++) dp[i][1]=1;
	for (int i=0; i<10; i++){
		for (int j=2; j<=n; j++){
			for (int k=0; k<=i; k++) dp[i][j]+=dp[k][j-1];
		}
	}
	ll ans=0;
	for (int i=0; i<=9; i++){
		ans+=dp[i][n];
		ans%=MOD;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << tinh(n) << "\n";
	}
	return 0;
}

