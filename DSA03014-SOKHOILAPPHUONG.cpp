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

int n,ans,x[100];
string s;

bool check (ll n){
	ll tmp=cbrt(n)+0.5;
	return tmp*tmp*tmp==n;
}

void Try (int i){
	for (int j=0; j<=1; j++){
		x[i]=j;
		if (i==n-1){
			ll tmp=0;
			for (int k=0; k<n; k++){
				if (x[k]){
					tmp=tmp*10+s[k]-'0';
				}
			}
			if (check(tmp) && tmp>ans) ans=tmp;
		}
		else Try(i+1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		cin >> s;
		ans=0;
		n=sz(s);
		Try(0);
		if (ans==0) cout << -1 << "\n";
		else cout << ans << "\n";
	}
	return 0;
}