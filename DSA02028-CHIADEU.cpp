#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int n,k,sum,ans;
int x[15],a[15];

void Try (int i, int cnt){
	if (cnt==k && x[cnt-1]==sum && i==n){
		++ans; return;
	}
	for (int j=i; j<n; j++){
		x[cnt]+=a[j];
		if (x[cnt]==sum){
			Try(j+1,cnt+1);
			for (int m=cnt+1; m<=k; m++){
				x[m]=0;
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> a[i];
		sum+=a[i];
	}
	if (sum%k!=0) cout << "0\n";
	else{
		sum/=k;
		Try(0,0);
		cout << ans;
	}
	return 0;
}