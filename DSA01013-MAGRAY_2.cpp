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

void solve(string s){
	string res="";
	res+=s[0];
	for (int i=1; i<s.size(); i++){
		if (s[i]=='1'){
			if (res[i-1]=='0') res+="1";
			else res+="0";
		}else res+=res[i-1];
	}
	cout << res << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		solve(s);
	}
	return 0;
}
