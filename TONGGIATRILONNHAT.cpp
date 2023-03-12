#include <bits/stdc++.h>
using namespace std;

int dp[5001][10001];

int main(){
    int n, m; cin >> n >> m;
    pair <int, int> p[n + 1];
    for (int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    for (int j = 0; j <= m; ++j) dp[0][j] = 0;
    for (int i = 1; i <= n; ++i){
    	for (int j = 1; j <= m; ++j){
    		dp[i][j] = dp[i - 1][j];
    		if (j >= p[i].first) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i].first] + p[i].second);
		}
	}
	cout << dp[n][m];
    return 0;
}

