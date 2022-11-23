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

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int i=s.size()-1;
		while (i>=0 && s[i]=='0'){
			s[i]='1';
			--i;
		}
		if (i==-1){
			for (int i=0; i<s.size(); i++) s[i]='1';
		}else{
			s[i]='0';
		}
		cout << s << endl;
	}
	return 0;
}
