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

int p[10]={2,3,5,7,11,13,17,19,23,29};
int n;

ll Try (int pos, ll cnt, ll x){
	if (cnt==n) return x;
	ll tmp=1e18+5;
	int i=1;
	while (1){
		x*=p[pos];
		if (x>tmp) break;
		if (cnt*(i+1)>n) break;
		tmp=min(tmp,Try(pos+1,cnt*(i+1),x));
		++i;
	}
	return tmp;
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		cin >> n;
		cout << Try(0,1,1) << "\n";
	}
	return 0;
}