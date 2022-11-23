#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int dp[1000001];

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		ms(dp,0);
		int n,k; cin >> n >> k;
		dp[0]=1; dp[1]=1;
		for (int i=2; i<=n; i++){
			for (int j=1; j<=min(i,k); j++){
				dp[i]=(dp[i]+dp[i-j])%MOD;
			}
		}
		cout << dp[n] << "\n";
	}
	return 0;
}