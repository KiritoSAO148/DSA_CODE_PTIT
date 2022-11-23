#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

vector<vector<int>> hoanvi, chinhhop;
int x[100],a[100],ok;

void Try(int i){
	for (int j=1; j<=3; j++){
		x[i]=j;
		if (i==4){
			vi tmp(x+1,x+5);
			chinhhop.pb(tmp);
		}else Try(i+1);
	}
}

void init(){
	int a[]={1,2,3,4,5};
	do{
		vi tmp(a,a+5);
		hoanvi.pb(tmp);
	}while (next_permutation(a,a+5));
	Try(1);
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	init();
	while (t--){
		ok=false;
		for (int i=1; i<=5; i++) cin >> a[i];
		for (auto it1 : hoanvi){
			for (auto it2 : chinhhop){
				int res=a[it1[0]];
				for (int k=0; k<4; k++){
					if (it2[k]==1){
						res+=a[it1[k+1]];
					}
					else if (it2[k]==2){
						res-=a[it1[k+1]];
					}else{
						res*=a[it1[k+1]];
					}
				}
				if (res==23){
					ok=true; break;
				}
			}
			if (ok) break;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}