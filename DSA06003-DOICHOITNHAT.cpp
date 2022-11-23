#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TC() int t; cin >> t; while (t--)
#define el cout << "\n"
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn 

const int MOD = (int) 1e9+7;

void FileIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int solve (int a[], int n){
	pii aPos[n];
	f0 (i,n){
		aPos[i].fi = a[i];
		aPos[i].se = i;
	}
	sort(aPos, aPos + n);
	vector <bool> vis(n, false);
	int ans = 0;
	f0 (i,n){
		if (vis[i] || aPos[i].se == i) continue;
		int cycle_size = 0, j = i;
		while (!vis[j]){
			vis[j] = 1;
			j = aPos[j].se;
			++cycle_size;
		}
		if (cycle_size > 0) ans += (cycle_size - 1);
	}
	return ans;
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	int n; cin >> n;
    	int a[n];
    	f0 (i,n) cin >> a[i];
    	cout << solve(a,n); el;
    }
    return 0;
}