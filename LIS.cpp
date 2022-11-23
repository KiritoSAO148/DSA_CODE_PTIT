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
#define maxn 5000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int n, a[maxn+1], L[maxn+1], T[maxn+1];

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	FastIO;
	int n; cin >> n;
	f1 (i,n) cin >> a[i];
	a[0]=-1e9; a[n+1]=1e9;
	L[n+1]=1;
	for (int i=n; i>=0; i--){
		int jmax=n+1;
		for (int j=i+1; j<=n+1; j++){
			if (a[j]>a[i] && L[j]>L[jmax]) jmax=j;
		}
		L[i]=L[jmax]+1;
		T[i]=jmax;
	}
	cout << L[0]-2 << "\n";
	int i=T[0];
	while (i!=n+1){
		cout << a[i] << " ";
		i=T[i];
	}
	return 0;
}