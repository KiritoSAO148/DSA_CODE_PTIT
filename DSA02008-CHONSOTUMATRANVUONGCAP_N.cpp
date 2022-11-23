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

int n,k,a[1005];

int main(){
	cin >> n >> k;
	int mt[n+1][n+1];
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> mt[i][j];
		}
	}
	for (int i=1; i<=n; i++) a[i]=i;
	vector <string> v;
	do{
		int sum=0;
		for (int i=1; i<=n; i++){
			sum += mt[i][a[i]];
		}
		if (sum == k){
			string res="";
			for (int i=1; i<=n; i++){
				res+=to_string(a[i]);
				res+=" ";
			}
			v.push_back(res);
		}
	}while (next_permutation(a+1,a+n+1));
	cout << v.size() << endl;
	for (string x : v) cout << x << endl;
	return 0;
}
