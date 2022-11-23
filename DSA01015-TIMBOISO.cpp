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

int res[501],ok;
vector <string> ans;
string s;

void sinh(){
	int i=s.size()-1;
	while (i >= 0 && s[i]=='9'){
		s[i]='0';
		i--;
	}
	if (i == -1) ok=false;
	else s[i]='9';
}

int main(){
	s="00000000000000";
	ok=true;
	while(ok){
		ans.push_back(s);
		sinh();
	}
	for (int i=1; i<=500; i++){
		for (string x : ans){
			long long tmp = stoll(x);
			if (tmp!=0 && tmp%i==0){
				res[i]=tmp;
				break;
			}
		}
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << res[n] << endl;
	}
	return 0;
}
