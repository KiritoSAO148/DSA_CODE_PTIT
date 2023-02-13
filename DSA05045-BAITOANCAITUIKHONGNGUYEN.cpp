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

multimap <double, int> mp;

void solve (vi c, vi w, int W, int n){
	double maxx = 0;
	f0 (i,n){
		mp.insert({(double) c[i] / w[i], i});
	}
	for (multimap <double, int> :: reverse_iterator it = mp.rbegin(); it != mp.rend(); ++it){
		double fraction = (double) W / w[it->se];
		if (W >= 0 && W >= w[it->se]){
			maxx += c[it->se];
			W -= w[it->se];
		}else if (W < w[it->se]){
			maxx += fraction * c[it->se];
			break;
		}
	}
	cout << fixed << setprecision(2) << maxx; el;
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	mp.clear();
    	int n, W; cin >> n >> W;
    	vi c(n), w(n);
    	f0 (i,n) cin >> c[i] >> w[i];
    	solve(c, w, W, n);
    }
    return 0;
}