#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int n, M, C[maxn+1], W[maxn+1], F[maxn+1][maxn+1];

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	FastIO;
	int t; cin >> t;
	while (t--){
		cin >> n >> M;
		ms(F[0],0);
		f1 (i,n) cin >> W[i];
		f1 (i,n) cin >> C[i];
		f1 (i,n){
			f1 (j,M){
				F[i][j]=F[i-1][j];
				if (j>=W[i])
					F[i][j]=max(F[i][j],F[i-1][j-W[i]]+C[i]);
			}
		}
		cout << F[n][M] << "\n";
		while (n!=0){
			if (F[n][M]!=F[n-1][M]){
				cout << n << ' ';
				M-=W[n];
			}
			--n;
		}
	}
	return 0;
}