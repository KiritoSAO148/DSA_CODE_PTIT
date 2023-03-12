#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >> s;
	int dp[201];
	memset(dp, 0, sizeof(dp));
	int res = INT_MIN;
	for (int i = 0; i < s.size(); ++i){
		dp[i] = 1;
		for (int j = 0; j < i; ++j){
			if (s[j] <= s[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}
