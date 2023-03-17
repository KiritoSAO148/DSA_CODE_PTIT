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

int main(){
    //FileIO();
    FastIO;
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, t = 0, d = 0;
    f0 (i,n){
    	if (s[i] == 'X') ++x;
    	else if (s[i] == 'T') ++t;
    	else ++d;
	}
	int cnt = 0;
	for (int i = 0; i < x; ++i){
		if (s[i] != 'X') ++cnt;
	}
	for (int i = n - d; i < n; ++i){
		if (s[i] != 'D') ++cnt;
	}
	int x1 = 0, d1 = 0;
	for (int i = 0; i < x; ++i){
		if (s[i] == 'D') ++d1;
	}
	for (int i = n - d; i < n; ++i){
		if (s[i] == 'X') ++x1;
	}
	cout << cnt - min(x1, d1);
    return 0;
}

