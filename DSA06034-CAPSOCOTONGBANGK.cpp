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

int first_pos(int a[], int l, int r, int x){
	int res=-1;
	while (l<=r){
		int m=(l+r)/2;
		if (a[m]==x){
			res=m;
			r=m-1;
		}else if (a[m]>x){
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return res;
}

int last_pos(int a[], int l, int r, int x){
	int res=-1;
	while (l<=r){
		int m=(l+r)/2;
		if (a[m]==x){
			res=m;
			l=m+1;
		}else if (a[m]>x){
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return res;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n, x; cin >> n >> x;
		int a[n];
		for (int &x : a) cin >> x;
		sort(a,a+n);
		ll cnt=0;
		for (int i=0; i<n-1; i++){
			int l=first_pos(a,i+1,n-1,x-a[i]);
			int r=last_pos(a,i+1,n-1,x-a[i]);
			if (l!=-1){
				cnt+=r-l+1;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

