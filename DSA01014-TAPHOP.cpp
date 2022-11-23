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

int n,k,s,a[1005],cnt;
bool ok;

void Try(int i){
	for (int j=a[i-1]+1; j<=n-k+i; j++){
		a[i]=j;
		if (i==k){
			int sum=0;
			for (int m=1; m<=k; m++) sum+=a[m];
			if (sum==s) ++cnt;
		}else Try(i+1);
	}
}

int main(){
	while (1){
		cin >> n >> k >> s;
		if (n+k+s==0) break;
		cnt=0;
		Try(1);
		cout << cnt << endl;
	}
	return 0;
}
