#include <bits/stdc++.h>
using namespace std;
 
#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
 
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int n,a[1005],k;

void sinh(){
	int i=k;
	while (i>=1 && a[i]==n-k+i) --i;
	if (i==0){
		for (int i=1; i<=k; i++) a[i]=i;
	}else{
		a[i]++;
		for (int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
	}
	
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i=1; i<=k; i++) cin >> a[i];
		sinh();
		for (int i=1; i<=k; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
