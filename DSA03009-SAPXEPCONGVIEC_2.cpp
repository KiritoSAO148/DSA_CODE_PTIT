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

struct job{
	int id, deadline, profit;
};

bool cmp (job a, job b){
	return a.profit>b.profit;
}

bool used[1001];
job a[1001];

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i=0; i<n; i++) cin >> a[i].id >> a[i].deadline >> a[i].profit;
		sort(a,a+n,cmp);
		ms(used,false);
		int sum=0;
		int res=0;
		for (int i=0; i<n; i++){
			for (int j=a[i].deadline; j>0; j--){
				if (!used[j]){
					used[j]=true;
					++res;
					sum+=a[i].profit;
					break;
				}
			}
		}
		cout << res << " " << sum << "\n";
	}
	return 0;
}