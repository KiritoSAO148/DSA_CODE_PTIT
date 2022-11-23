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

int n,q,x,y,a[1000001],ok;

void ktao(){
	for (int i=1; i<=n; i++) a[i]=0;
}

void solve(){
	for (int i=x; i<=y; i++){
		if (a[i]==0) a[i]=1;
		else a[i]=0;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> q;
	while (q--){
		cin >> x >> y;
		solve();
	}
	for (int i=1; i<=n; i++) cout << a[i] << " ";
	return 0;
}