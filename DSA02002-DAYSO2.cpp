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

void Try(int i){
	if (i==0) return;
	for (int j=1; j<i; j++){
		a[j]+=a[j+1];
	}
	Try(i-1);
	cout << "[";
	for (int j=1; j<=i; j++){
		cout << a[j];
		if (j==i) cout << "] ";
		else cout << " ";
	}
	for (int j=i; j>=1; j--){
		a[j]-=a[j+1];
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i=1; i<=n; i++){
			cin >> a[i];
		}
		Try(n);
		cout << endl;
	}
	return 0;
}
