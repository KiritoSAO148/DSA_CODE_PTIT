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

int n,a[100005],x;

bool cmp(int a, int b){
	return abs(x-a)<abs(x-b);
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> x;
		for (int i=0; i<n; i++) cin >> a[i];
		stable_sort(a,a+n,cmp);
		for (int i=0; i<n; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
