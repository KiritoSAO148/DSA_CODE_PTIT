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
		int n; cin >> n;
		int a[n];
		vi dp1(n, 1), dp2(n, 1);
		for (int i=0; i<n; i++) cin >> a[i];
		int ans=0;
		for (int i=1; i<n; i++){
			if (a[i]>a[i-1]) dp1[i]+=dp1[i-1];
		}
		for (int i=n-2; i>=0; i--){
			if (a[i]>a[i+1]) dp2[i]+=dp2[i+1];
		}
		for (int i=0; i<n; i++) ans=max(ans, dp1[i]+dp2[i]-1);
		cout << ans << "\n";
	}
	return 0;
}