#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn 1000
#define maxk 50

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int n, k, a[maxn+1], dp[maxn+1][maxk+1];

int sub (int x, int y){
	int res=0;
	int tmp=(x-y)%k;
	if (tmp>=0) res=tmp;
	else res=tmp+k;
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	FastIO;
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		ms(dp,0);
		int sum=0;
		f1 (i,n){
			cin >> a[i];
			sum+=a[i];
		}
		for (int i=1; i<=k; i++) dp[0][i]=1e9;
		dp[0][0]=0;
		f1 (i,n){
			for (int t=0; t<=k-1; t++){
				dp[i][t]=min(dp[i-1][t],dp[i-1][sub(t,a[i])]+1);
			}
		}
		cout << n-dp[n][sum%k] << "\n";
	}
	return 0;
}