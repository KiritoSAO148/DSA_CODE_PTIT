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

void Try(string s, int k){
	for (int i=0; i<s.size(); i++){
		if (k==0) break;
		char c=s[s.size()-1];
		int pos=s.size()-1;
		for (int j=i+1; j<s.size(); j++){
			if (s[j]>=c){
				c=s[j];
				pos=j;
			}
		}
		if (c>s[i]){
			swap(s[pos],s[i]);
			--k;
		}
	}
	cout << s << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		int k;
		string s;
		cin >> k >> s;
		Try(s,k);
	}
	return 0;
}
