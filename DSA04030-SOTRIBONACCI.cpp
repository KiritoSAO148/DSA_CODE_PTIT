#include <iostream>
#include <vector>
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

const ll MOD = 1000000000000007;

void FileIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

struct Matrix {
    ll f[4][4];
} a, b;

ll F[5], T[5];

ll mul(ll a, ll b) {
    ll c = 0;
    while (b) {
        if (b & 1) {
            c += a;
            c %= MOD;
        }
        a += a;
        a %= MOD;
        b /= 2;
    }
    return c;
}

Matrix operator * (Matrix a, Matrix b) {
    Matrix c;
    f0 (i,4)
        f0 (j,4) {
            c.f[i][j] = 0;
            f0 (k,4)
                c.f[i][j] = (c.f[i][j] + mul(a.f[i][k], b.f[k][j])) % MOD;
        }
    return c;
}

Matrix powmod (int p) {
    if (p == 1) return a;
    Matrix x = powmod(p / 2);
    x = x * x;
    if (p & 1) x = x * a;
    return x;
}

int main(){
    FileIO();
    FastIO;
    int t; scanf("%d", &t);
    a.f[0][0] = a.f[0][1] = a.f[1][1] = a.f[1][2] = a.f[1][3] = a.f[2][1] = a.f[3][2] = 1;
    F[1] = 1; F[2] = 3; F[3] = 6; T[1] = 1; T[2] = 2; T[3] = 3;
    while (t--) {
        int n; scanf("%d", &n);
        if (n <= 3) printf("%lld\n", F[n]);
        else {
            b = powmod(n - 2);
            printf("%lld\n", (F[2] * b.f[0][0] + T[3] * b.f[0][1] + T[2] * b.f[0][2] + T[1] * b.f[0][3]) % MOD);
        }
    }
    return 0;
}