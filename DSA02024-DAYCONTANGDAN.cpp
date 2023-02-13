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

int n, a[25], x[25];
vector <string> v;

void Try (int i, int pos){
    for (int j = pos; j <= n; ++j){
        if (a[j] > x[i - 1]){
            x[i] = a[j];
            if (i >= 2){
                string tmp = "";
                f1 (k, i){
                    tmp += to_string(x[k]);
                    if (k != i) tmp += " ";
                }
                v.pb(tmp);
            }
            Try(i + 1, j + 1);
        }
    }
}

int main(){
    FileIO();
    FastIO;
    cin >> n;
    f1 (i,n) cin >> a[i];
    Try(1, 1);
    sort(all(v));
    for (string x : v) cout << x << '\n';
    return 0;
}
