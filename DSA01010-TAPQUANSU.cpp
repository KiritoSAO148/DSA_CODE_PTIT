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

int n,a[1005],k;
set <int> s;

void sinh(){
	int i=k;
	while (i>=1 && a[i]==n-k+i) --i;
	if (i==0) cout << k << endl;
	else{
		++a[i];
		for (int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
		int cnt=0;
		for (int i=1; i<=k; i++){
			if (s.count(a[i])==1) ++cnt;
		}
		cout << k-cnt << endl;
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i=1; i<=k; ++i){
			cin >> a[i];
			s.insert(a[i]);
		}
		sinh();
		s.clear();
	}
	return 0;
}
