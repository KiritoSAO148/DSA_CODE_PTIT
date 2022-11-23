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

string s;
int n, len;

char find (ll n, ll k){
	if (n<=sz(s)) return s[n-1];
	if (n<=k/2) return find(n,k/2);
	else{
		if (k>1) return find(n-1-k/2,k/2);
		return find(1,k/2);
	}
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
		cin >> s >> n;
		len=sz(s);
		while (len<n) len*=2;
		cout << find(n,len) << "\n";
	}
	return 0;
}