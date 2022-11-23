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

int n;
int in[10001], level[10001], mark[10001];

void inp(){
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> in[i];
		mark[in[i]]=i;
	}
	for (int i=1; i<=n; i++){
		cin >> level[i];
	}
}

void solve(int l, int r){
	if (l>r) return;
	if (l==r) cout << in[l] << " ";
	else{
		int pos;
		for (int i=1; i<=n; i++){
			if (mark[level[i]]>=l && mark[level[i]]<=r){
				pos=level[i]; break;
			}
		}
		pos=mark[pos];
		solve(l, pos-1);
		solve(pos+1, r);
		cout << in[pos] << " ";
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
		inp();
		solve(1,n);
		cout << "\n";
	}
	return 0;
}