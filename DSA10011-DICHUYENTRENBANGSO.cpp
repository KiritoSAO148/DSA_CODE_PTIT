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

int n, m, a[500][500], dp[500][500];

int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};

struct cell{
	int x,y;
	int dis;
	cell (int x, int y, int dis)
	: x(x)
	, y(y)
	, dis(dis)
	{
	}
};

bool operator<(const cell& a, const cell& b){
    if (a.dis == b.dis) {
        if (a.x != b.x) return (a.x < b.x);
        return (a.y < b.y);
    }
    return (a.dis < b.dis);
}

bool check(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int solve(){
    f0 (i,n) f0 (j,m) dp[i][j] = INT_MAX;
    set<cell> st;
    st.insert(cell(0, 0, 0));
    dp[0][0] = a[0][0];
    while (!st.empty()) {
        cell k = *st.begin();
        st.erase(st.begin());
        for (int i = 0; i < 4; ++i) {
            int x = k.x + dx[i];
            int y = k.y + dy[i];
            if (!check(x, y))
                continue;
            if (dp[x][y] > dp[k.x][k.y] + a[x][y]) {
                if (dp[x][y] != INT_MAX)
                    st.erase(st.find(cell(x, y, dp[x][y])));
                dp[x][y] = dp[k.x][k.y] + a[x][y];
                st.insert(cell(x, y, dp[x][y]));
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main(){
    FileIO();
    FastIO;
    TC(){
    	cin >> n >> m;
    	ms(dp,0);
    	f0 (i,n) f0 (j,m) cin >> a[i][j];
    	cout << solve(); el;
    }
    return 0;
}
