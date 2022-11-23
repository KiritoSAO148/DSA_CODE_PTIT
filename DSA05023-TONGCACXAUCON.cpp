#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int n=s.size();
		ll dp[15];
		ll ans=0;
		memset(dp,0,sizeof(dp));
		dp[0]=s[0]-'0';
		ans=dp[0];
		for (int i=1; i<n; i++){
			dp[i]=dp[i-1]*10+(s[i]-'0')*(i+1);
			ans+=dp[i];
		}
		cout << ans << endl;
	}
	return 0;
}
