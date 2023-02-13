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

int n, a[15], s, x[15];
vector <vi> v;

void Try (int i, int sum, int pos){
    if (sum == s){
        vi tmp(x + 1, x + i);
        v.pb(tmp);
    }
    for (int j = pos; j <= n; ++j){
        if (a[j] + sum <= s){
            x[i] = a[j];
            Try(i + 1, sum + a[j], j + 1);
        }
    }
}

int main(){
    FileIO();
    FastIO;
    TC(){
        cin >> n >> s;
        v.clear();
        f1 (i,n) cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 0, 1);
        if (sz(v) == 0) cout << "-1\n";
        else {
            for (auto it : v){
                cout << "[";
                for (int i = 0; i < sz(it); ++i){
                    cout << it[i];
                    if (i != sz(it) - 1) cout << " ";
                    else cout << "] ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
