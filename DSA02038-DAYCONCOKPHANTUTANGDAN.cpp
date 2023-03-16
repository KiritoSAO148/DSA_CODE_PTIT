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

int n, k, a[20], x[20], ok;
vvi v;

void init(){
	f1(i,k) x[i] = i;
}

void next(){
	int i = k;
	while (i >= 1 && x[i] == n - k + i) --i;
	if (i == 0) ok = false;
	else{
		++x[i];
		for (int j = i + 1; j <= k; ++j) x[j] = x[j - 1] + 1;
	}
}

int main(){
    //FileIO();
    FastIO;
    TC(){
    	cin >> n >> k;
    	f1 (i,n) cin >> a[i];
    	sort(a + 1, a + n + 1);
    	ok = true;
    	v.clear();
    	init();
    	while (ok){
    		vi res;
    		f1(i,k) res.pb(a[x[i]]);
    		v.pb(res);
    		next();
		}
		for (auto it : v){
			for (int x : it) cout << x << ' ';
			el;
		}
	}
    return 0;
}

