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

int n;
string a[1005];
bool ok;

void ktao(){
	for (int i=1; i<=n; i++) a[i]='A';
}

void sinh(){
	int i=n;
	while (i>=1 && a[i]=="B"){
		a[i]="A";
		--i;
	}
	if (i==0) ok=false;
	else a[i]='B';
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		ok=true;
		ktao();
		while (ok){
			for (int i=1; i<=n; i++){
				cout << a[i];
			}
			cout << " ";
			sinh();
		}
		cout << endl;
	}
	return 0;
}
