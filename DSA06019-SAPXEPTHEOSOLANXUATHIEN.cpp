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

map<int,int>m;

bool cmp(int a, int b){
	if (m[a]!=m[b]) return m[a]>m[b];
	return a<b;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a){
			cin >> x;
			m[x]++;
		}
		sort(a,a+n,cmp);
		for (int x : a) cout << x << " ";
		cout << endl;
		m.clear();
	}
	return 0;
}
