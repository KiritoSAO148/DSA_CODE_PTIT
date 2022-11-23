#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int n,a[1005];
bool ok;

void ktao(){
	for (int i=1; i<=n; i++) a[i]=0;
}

void sinh(){
	int i=n;
	while (i>=1 && a[i]==1){
		a[i]=0;
		--i;
	}
	if (i==0) ok=false;
	else a[i]=1;
}

void solve (string s){
	cout << s[0];
	for (int i=1; i<s.size(); i++){
		if (s[i]==s[i-1]) cout << 0;
		else cout << 1;
	}
	cout << " ";
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		ok=true;
		ktao();
		while (ok){
			string s="";
			for (int i=1; i<=n; i++) s+=to_string(a[i]);
			solve(s);
			sinh();
		}
		cout << endl;
	}
	return 0;
}
