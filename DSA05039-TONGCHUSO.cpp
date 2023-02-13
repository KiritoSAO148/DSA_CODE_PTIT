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

int dp[101][10001];

int minDigit (int a, int b){
	if (a > b || a < 0 || a > 100 || b < 0 || b > 10000) return -1;
	if (a == 0 && b == 0) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	int ans = 101;
	for (int i = 9; i >= 1; --i){
		int k = minDigit(a - i, b - i * i);
		if (k != -1) ans = min(ans, k + 1);
	}
	return dp[a][b] = ans;
}

void solve (int a, int b){
	ms(dp, -1);
	dp[0][0] = 0;
	int k = minDigit(a, b);
	if (k == -1 || k > 100){
		cout << "-1\n"; return;
	}
	while (a > 0 && b > 0){
		for (int i = 1; i <= 9; ++i){
			if (a >= i && b >= i * i && dp[a][b] == dp[a - i][b - i * i] + 1){
				cout << i;
				a -= i;
				b -= i * i;
				break;
			}
		}
	}
	el;
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	int a, b; cin >> a >> b;
    	solve(a, b);
    }
    return 0;
}