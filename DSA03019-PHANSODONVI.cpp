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

void Try (ll tu, ll mau){
	if (mau%tu==0){
		cout << 1 << "/" << mau/tu << "\n";
		return;
	}
	ll x=mau/tu+1;
	cout << 1 << "/" << x << " + ";
	ll maumoi=mau*x;
	ll tumoi=tu*x-mau;
	Try(tumoi,maumoi);
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
		ll tu,mau; cin >> tu >> mau;
		Try(tu,mau);
	}
	return 0;
}