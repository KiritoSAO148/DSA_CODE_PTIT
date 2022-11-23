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

int tinh (string s){
	int cnt=0;
	for (int i=0; i<sz(s); i++){
		if (s[i]=='0' || s[i]=='4' || s[i]=='8') ++cnt;
	}
	for (int i=0; i<sz(s)-1; i++){
		int tmp=(s[i]-'0')*10+(s[i+1]-'0');
		if (tmp%4==0) cnt=cnt+i+1;
	}
	return cnt;
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s; cin >> s;
	cout << tinh(s);
	return 0;
}