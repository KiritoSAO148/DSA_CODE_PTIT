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

int n=8, X[100], cot[100], d1[100], d2[100], ans; int a[100][100];

void ktao(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	memset(cot,0,sizeof(cot));
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
}

void Try(int i){
	for (int j=1; j<=n; j++){
		if (cot[j]==0 && d1[i-j+n]==0 && d2[i+j-1]==0){
			X[i]=j;
			cot[j]=1;
			d1[i-j+n]=1;
			d2[i+j-1]=1;
			if (i==n){
				int sum=0;
				for (int k=1; k<=n; k++){
					sum+=a[k][X[k]];
				}
				ans=max(ans,sum);
			}else Try(i+1);
			cot[j]=0;
			d1[i-j+n]=0;
			d2[i+j-1]=0;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		ktao();
		ans=INT_MIN;
		Try(1);
		cout << ans << endl;
	}
	return 0;
}
