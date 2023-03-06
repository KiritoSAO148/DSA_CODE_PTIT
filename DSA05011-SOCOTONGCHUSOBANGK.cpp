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

ll dp[101][5001];
int n, k;

void init(){
	f1 (i,9) dp[1][i] = 1;
	for (int i = 2; i <= 100; ++i){
		for (int j = 1; j <= 5000; ++j){
			for (int d = 0; d <= 9; ++d){
				if (j >= d) {
					dp[i][j] += dp[i - 1][j - d];
					dp[i][j] %= MOD;
				}
			}
		}
	}
}

int main(){
    FileIO();
    FastIO;
    init();
    TC(){
    	cin >> n >> k;
    	cout << dp[n][k]; el;
    }
    return 0;
}