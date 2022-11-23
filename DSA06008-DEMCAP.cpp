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

int first_pos(int a[], int l, int r, int x){
	int res = -1 ;
	while(l <= r){
		int m = (l+r) / 2;
		if(a[m] > x){
			res = m ;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	return res;
}

int cnt[5];

int count(int y[], int m, int x){
	if(x==0) return 0;
	if (x == 1) return cnt[0];
	int ans=0;
	int i1 = first_pos(y, 0, m-1, x);
	if(i1!=-1) ans = m - i1;
	ans+=(cnt[0]+cnt[1]);
	if(x==2) ans = ans - cnt[3] - cnt[4];
	if(x==3) ans += cnt[2];
	return ans;
}

void solve(){
	int n, m ; cin >> n >> m;
	ms(cnt,0);
	int x[n], y[m];
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < m; i++){
		cin >> y[i];
		if(y[i] <= 4){
			cnt[y[i]]++;
		}
	}
	sort(y, y + m);
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += count(y, m, x[i]);
	}
	cout << ans << "\n";
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
		solve();
	}
	return 0;
}