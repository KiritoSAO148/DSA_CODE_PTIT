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

int solve (int a[], int n, ll k){
	unordered_map <ll, int> mp;
	ll curr = 0;
	int res = 0;
	f0 (i,n){
		curr += a[i];
		if (curr == k) ++res;
		if (mp.find(curr - k) != mp.end()) res += mp[curr - k];
		mp[curr]++;
	}
	return res >= 1;
}

int main(){
    //FileIO();
    FastIO;
    TC(){
    	int n; ll k; cin >> n >> k;
    	int a[n];
    	f0 (i,n) cin >> a[i];
    	if (solve(a, n, k)) cout << "YES\n";
    	else cout << "NO\n";
    }
    return 0;
}
