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

int n,cnt,a[50],ok;
vector<vector<int>>v;

void ktao(){
	cnt=1;
	a[1]=n;
}

void sinh(){
	int i=cnt;
	while (i>=1 && a[i]==1) --i;
	if (i==0) ok=false;
	else{
		a[i]--;
		int thieu=cnt-i+1;
		int x=thieu/a[i];
		int y=thieu%a[i];
		cnt=i;
		for (int j=1; j<=x; j++){
			a[cnt+1]=a[i];
			++cnt;
		}
		if (y){
			a[cnt+1]=y;
			++cnt;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		cin >> n;
		ok=1;
		ktao();
		while (ok){
			vi res(a+1,a+cnt+1);
			v.pb(res);
			sinh();
		}
		for (auto it : v){
			cout << "(";
			for (int i=0; i<sz(it); i++){
				cout << it[i];
				if (i!=sz(it)-1) cout << " ";
				else cout << ") ";
			}
		}
		v.clear();
		cout << "\n";
	}
	return 0;
}