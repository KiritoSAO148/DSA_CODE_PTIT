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

int cnt=0;

void solve(string s){
	int i=s.size()-2;
	while (i>=0 && s[i]>=s[i+1]) --i;
	if (i==-1) cout << "BIGGEST" << endl;
	else{
		int j=s.size()-1;
		while (s[i]>=s[j]) --j;
		swap(s[i],s[j]);
		reverse(s.begin()+i+1,s.end());
		for (int i=0; i<s.size(); i++) cout << s[i];
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		++cnt;
		int tt; cin >> tt;
		string s; cin >> s;
		cout << cnt << " ";
		solve(s);
		cout << endl;
	}
	return 0;
}
