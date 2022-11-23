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

bool check(){
	int ans=0, cnt=0;;
	for (int i=1; i<=n; i++){
		if (a[i]==0) ++cnt;
		else cnt=0;
		if (cnt>k) return false;
		if (cnt==k) ++ans;
	}
	return ans==1;
}

int main(){
	cin >> n >> k;
	ok=true;
	ktao();
	vector <string> v;
	while (ok){
		if (check()){
			string s="";
			for (int i=1; i<=n; i++){
				if (a[i]==0) s+="A";
				else s+="B";
			}
			v.pb(s);
		}
		sinh();
	}
	cout << v.size() << endl;
	for (int i=0; i<v.size(); i++) cout << v[i] << endl;
	return 0;
}
