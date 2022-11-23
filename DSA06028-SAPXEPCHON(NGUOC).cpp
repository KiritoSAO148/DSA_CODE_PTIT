#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

typedef long long ll;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	int n; cin >> n;
	int a[n];
	for (int &x : a) cin >> x;
	vector<int> res[n];
	for (int i=0; i<n-1; i++){
		int min_idx=i;
		for (int j=i+1; j<n; j++){
			if (a[j]<a[min_idx]) min_idx=j;
		}
		swap(a[i],a[min_idx]);
		for (int j=0; j<n; j++) res[i].pb(a[j]);
	}
	for (int i=n-2; i>=0; i--){
		cout << "Buoc " << i+1 << ": ";
		for (int x : res[i]){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
